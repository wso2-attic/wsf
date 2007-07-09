#!/bin/bash


this_dir=$PWD
src_dist=rampartc-src-0.90
src_dist_tar_gz=$src_dist.tar.gz
src_dist_tar_gz_md5=$src_dist_tar_gz.md5
src_dist_tar_gz_asc=$src_dist_tar_gz.asc
src_dist_zip=$src_dist.zip
src_dist_zip_md5=$src_dist_zip.md5
src_dist_zip_asc=$src_dist_zip.asc

echo "Clean archives if any"
rm $src_dist_tar_gz
rm $src_dist_zip

make dist

echo "Extract tar"

tar -xzvf $src_dist_tar_gz
rm $src_dist_tar_gz

ls

cd $src_dist

echo "Removing makefiles in $src_dist"
for i in `find . -name "Makefile"`
do
    echo "Deleting $i"
    rm  $i
done

echo "Removing .svn entries in $src_dist"
for i in `find . -name ".svn"`
do
    echo "Deleting $i"
    rm  -rf $i
done

echo "Removing .la entries in $src_dist"
for i in `find . -name "*.la"`
do
    echo "Deleting $i"
    rm  $i
done

echo "Removing .lo entries in $src_dist"
for i in `find . -name "*.lo"`
do
    echo "Deleting $i"
    rm  $i
done

echo "Removing .libs entries in $src_dist"
for i in `find . -name ".libs"`
do
    echo "Deleting $i"
    rm  -rf $i
done

echo "Removing .deps entries in $src_dist"
for i in `find . -name ".deps"`
do
    echo "Deleting $i"
    rm  -rf $i
done

cd $this_dir

echo "Make the tar and its friends"
tar -czvf $src_dist_tar_gz $src_dist
openssl md5 < $src_dist_tar_gz > $src_dist_tar_gz_md5
gpg --armor --output $src_dist_tar_gz_asc --detach-sig $src_dist_tar_gz


echo "Make the zip and its friends"
zip -r $src_dist_zip $src_dist
openssl md5 < $src_dist_zip > $src_dist_zip_md5
gpg  --armor --output $src_dist_zip_asc --detach-sig $src_dist_zip

echo "Done... :)"
