package org.wso2.wsf.wtp.ws.creation.core.utils;

import java.io.File;
import java.io.IOException;
import org.apache.tools.ant.Project;
import org.apache.tools.ant.taskdefs.Jar;
import org.wso2.wsf.wtp.ws.creation.core.messages.WSASCreationUIMessages;

public class AARFileWriter extends Jar{


    public AARFileWriter() {
        this.setProject(new Project());
        this.getProject().init();
        this.setTaskType(WSASCreationUIMessages.JAR_TASK);
        this.setTaskName(WSASCreationUIMessages.JAR_TASK);
        this.setOwningTarget(new org.apache.tools.ant.Target());
    }

    public void writeAARFile(File outputFolder,
    						 String outputFileName,
    						 File inputFileFolder) throws IOException,Exception {

        if (!outputFolder.exists()){
            outputFolder.mkdir(); //create the output path
        }else{
            if (!outputFolder.isDirectory())
                return;
        }

        File targetFile = new File(outputFolder,outputFileName);
        this.setBasedir(inputFileFolder);
        this.setDestFile(targetFile);

        //run the task
        this.perform();
    }

}