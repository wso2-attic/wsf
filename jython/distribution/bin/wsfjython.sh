#!/bin/sh
# ----------------------------------------------------------------------------
#  Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

# ----------------------------------------------------------------------------
# Main Script for the WSF/Jython
#
# Environment Variable Prequisites
#
#   WSFJYTHON_HOME    Home of WSF/Jython installation. If not set I will  try
#                     to figure it out.
#
#   JAVA_HOME         Must point at your Java Development Kit installation.
#
#   JAVA_OPTS         (Optional) Java runtime options used when the commands
#                     is executed.
# -----------------------------------------------------------------------------

DARWIN_TOOLS=""
# OS specific support.  $var _must_ be set to either true or false.
cygwin=false;
darwin=false;
os400=false;
mingw=false;
case "`uname`" in
CYGWIN*) cygwin=true;;
MINGW*) mingw=true;;
OS400*) os400=true;;
Darwin*) darwin=true
        if [ -z "$JAVA_VERSION" ] ; then
             JAVA_VERSION="CurrentJDK"
           else
             echo "Using Java version: $JAVA_VERSION"
           fi
           if [ -z "$JAVA_HOME" ] ; then
             JAVA_HOME=/System/Library/Frameworks/JavaVM.framework/Versions/${JAVA_VERSION}/Home
             DARWIN_TOOLS=$JAVA_HOME/Classes/Classes.jar
           fi
           ;;
esac

# resolve links - $0 may be a softlink
PRG="$0"

while [ -h "$PRG" ]; do
  ls=`ls -ld "$PRG"`
  link=`expr "$ls" : '.*-> \(.*\)$'`
  if expr "$link" : '.*/.*' > /dev/null; then
    PRG="$link"
  else
    PRG=`dirname "$PRG"`/"$link"
  fi
done

# Get standard environment variables
PRGDIR=`dirname "$PRG"`

# Only set WSFJYTHON_HOME if not already set
[ -z "$WSFJYTHON_HOME" ] && WSFJYTHON_HOME=`cd "$PRGDIR/.." ; pwd`

# For Cygwin, ensure paths are in UNIX format before anything is touched
if $cygwin; then
  [ -n "$JAVA_HOME" ] && JAVA_HOME=`cygpath --unix "$JAVA_HOME"`
  [ -n "$WSFJYTHON_HOME" ] && WSFJYTHON_HOME=`cygpath --unix "$WSFJYTHON_HOME"`
  [ -n "$CLASSPATH" ] && CLASSPATH=`cygpath --path --unix "$CLASSPATH"`
fi

# For OS400
if $os400; then
  # Set job priority to standard for interactive (interactive - 6) by using
  # the interactive priority - 6, the helper threads that respond to requests
  # will be running at the same priority as interactive jobs.
  COMMAND='chgjob job('$JOBNAME') runpty(6)'
  system $COMMAND

  # Enable multi threading
  export QIBM_MULTI_THREADED=Y
fi

# For Migwn, ensure paths are in UNIX format before anything is touched
if $mingw ; then
  [ -n "$WSFJYTHON_HOME" ] &&
    WSFJYTHON_HOME="`(cd "$WSFJYTHON_HOME"; pwd)`"
  [ -n "$JAVA_HOME" ] &&
    JAVA_HOME="`(cd "$JAVA_HOME"; pwd)`"
fi

if [ -z "$JAVACMD" ] ; then
  if [ -n "$JAVA_HOME"  ] ; then
    if [ -x "$JAVA_HOME/jre/sh/java" ] ; then
      # IBM's JDK on AIX uses strange locations for the executables
      JAVACMD="$JAVA_HOME/jre/sh/java"
    else
      JAVACMD="$JAVA_HOME/bin/java"
    fi
  else
    JAVACMD=java
  fi
fi

if [ ! -x "$JAVACMD" ] ; then
  echo "Error: JAVA_HOME is not defined correctly."
  echo " WSF/Jython cannot execute $JAVACMD"
  exit 1
fi

# if JAVA_HOME is not set we're not happy
if [ -z "$JAVA_HOME" ]; then
  echo "You must set the JAVA_HOME variable before running WSF/Jython."
  exit 1
fi

# update WSF/Jython classpath
WSFJYTHON_CLASSPATH=""
for f in "$WSFJYTHON_HOME"/lib/jars/*.jar
do
  WSFJYTHON_CLASSPATH="$WSFJYTHON_CLASSPATH":$f
done

for g in "$WSFJYTHON_HOME"/lib/mars/*.mar
do
  WSFJYTHON_CLASSPATH="$WSFJYTHON_CLASSPATH":$g
done

WSFJYTHON_CLASSPATH="$JAVA_HOME/lib/tools.jar":"$WSFJYTHON_CLASSPATH":"$CLASSPATH":"$DARWIN_TOOLS"

# For Cygwin, switch paths to Windows format before running java
if $cygwin; then
  JAVA_HOME=`cygpath --absolute --windows "$JAVA_HOME"`
  WSFJYTHON_HOME=`cygpath --absolute --windows "$WSFJYTHON_HOME"`
  CLASSPATH=`cygpath --path --windows "$CLASSPATH"`
  JAVA_ENDORSED_DIRS=`cygpath --path --windows "$JAVA_ENDORSED_DIRS"`
fi

# ---------- Handle the SSL Issue with proper JDK version --------------------
jdk_15=`$JAVA_HOME/bin/java -version 2>&1 | grep 1.5`
jdk_16=`$JAVA_HOME/bin/java -version 2>&1 | grep 1.6`
jdk_14=`$JAVA_HOME/bin/java -version 2>&1 | grep 1.4`

if [ "$jdk_14" ]; then
	echo " [ERROR] WSF/Jython is supported only on JDK 1.5 and higher"
	exit 1
elif [ "$jdk_15" ]; then
   WSFJYTHON_CLASSPATH="$WSFJYTHON_HOME/lib/jars/bcprov-jdk15-132.jar":$WSFJYTHON_CLASSPATH
elif [ "$jdk_16" ]; then
   WSFJYTHON_CLASSPATH="$WSFJYTHON_HOME/lib/jars/bcprov-jdk15-132.jar":$WSFJYTHON_CLASSPATH
else
   echo " [ERROR] Unsupported Java version"
fi

# ----- Execute The Requested Command -----------------------------------------

echo "$1"


cd "$WSFJYTHON_HOME"

        exec "$JAVACMD" \
        $JAVA_OPTS \
        -classpath "$WSFJYTHON_CLASSPATH" \
        -Djava.endorsed.dirs="$JAVA_HOME/jre/lib/endorsed":"$JAVA_HOME/lib/endorsed" \
        org.python.util.jython $1    