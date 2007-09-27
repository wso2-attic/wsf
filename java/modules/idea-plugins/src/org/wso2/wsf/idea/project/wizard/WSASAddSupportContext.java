package org.wso2.wsf.idea.project.wizard;

import com.intellij.ide.util.projectWizard.AddSupportContext;
import com.intellij.javaee.make.MakeUtil;
import com.intellij.openapi.command.WriteCommandAction;
import com.intellij.openapi.module.Module;
import com.intellij.openapi.options.ConfigurationException;
import com.intellij.openapi.project.Project;
import com.intellij.openapi.roots.*;
import com.intellij.openapi.roots.libraries.Library;
import com.intellij.openapi.roots.libraries.LibraryTable;
import com.intellij.openapi.roots.libraries.LibraryTablesRegistrar;
import com.intellij.openapi.roots.libraries.LibraryUtil;
import com.intellij.openapi.vfs.VirtualFile;

import java.io.IOException;

public class WSASAddSupportContext extends AddSupportContext {


    public WSASAddSupportContext(String libraryName, Project project, boolean insideAddModuleWizard) {
        super(libraryName, project, insideAddModuleWizard);
    }

    public void installSupport(final Module module, final ModifiableRootModel rootModel) {

        try {
            if (myLibrary != null || myJars.length > 0) {
                Library library = addLibrary(module, rootModel);

            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ConfigurationException e) {
            e.printStackTrace();
        }
    }

    public Library addLibrary(Module module, ModifiableRootModel rootModel) throws IOException, ConfigurationException {
        final Project project = module.getProject();

        final Library library = getExistentOrCreateNewLibrary(project);
        ModifiableRootModel modifiableModel = rootModel;
        if (modifiableModel == null || !modifiableModel.isWritable()) {

            final ModuleRootManager rootManager = ModuleRootManager.getInstance(module);
            boolean found = false;
            for (int i = 0; i < rootManager.getOrderEntries().length; i++) {
                OrderEntry entry = rootManager.getOrderEntries()[i]; 
                if (entry instanceof LibraryOrderEntry && ((LibraryOrderEntry) entry).getLibrary() == library) {
                    found = true;
                }
            }
            if (!found) {

                modifiableModel = rootManager.getModifiableModel();
                modifiableModel.addLibraryEntry(library);
                modifiableModel.commit();
            }
        } else {
            if (modifiableModel.findLibraryOrderEntry(library) == null) {
                modifiableModel.addLibraryEntry(library);

                modifiableModel.commit();
            }
        }
        MakeUtil.getInstance().addLibraryLink(module, library, rootModel);
        return library;
    }

    protected Library getExistentOrCreateNewLibrary(final Project project) {
        Library library;
        if (myLibrary != null) {
            library = myLibrary;
        } else {
            final LibraryTable libraryTable = LibraryTablesRegistrar.getInstance().
                    getLibraryTable(project);

            library = LibraryUtil.createLibrary(libraryTable, getLibraryName());
        }

        final Library.ModifiableModel libraryModel = library.getModifiableModel();

        for (int i = 0; i < myJars.length; i++) {
            VirtualFile virtualFile = myJars[i];
            libraryModel.addRoot(virtualFile, OrderRootType.CLASSES);
        }

        libraryModel.commit();
        return library;
    }

    public void installSupportInAction(final Module module, final ModifiableRootModel rootModel) {

        new WriteCommandAction.Simple(module.getProject(), getPotentiallyModifiedFiles(module)) {

            protected void run() throws Throwable {
                installSupport(module, rootModel);
            }
        }.execute();
    }

}
