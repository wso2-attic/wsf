#!/bin/bash

mkdir DataServices

rsync -r --exclude=.svn dbs2php  lib  README  samples DataServices

zip -r DataServices.zip DataServices
