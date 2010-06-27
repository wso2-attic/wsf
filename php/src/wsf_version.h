/**
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_VERSION_H
#define WSF_VERSION_H

/** major version */
#define WSF_MAJOR_VERSION 2

/** minor version */
#define WSF_MINOR_VERSION 1

/** patch level */ 
#define WSF_PATCH_VERSION 0

/** The formatted string of WSF version */
#define WSF_VERSION_STRING "2.1.0"

/* macro for Win32 .rc files using numeric csv representation */
#define WSF_VERSION_STRING_CSV WSF_MAJOR_VERSION ##, \
                             ##WSF_MINOR_VERSION ##, \
                             ##WSF_PATCH_VERSION

#endif   /* WSF_VERSION_H */
