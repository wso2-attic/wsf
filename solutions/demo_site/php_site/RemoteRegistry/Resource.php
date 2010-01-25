<?php
/*
 * Copyright (c) 2005-2008 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Represent Resources
 *
 */
class Resource
{
    public $id;
    public $author_username;
    public $created_time;
    public $last_updated_username;
    public $updated; //timestamp
    public $description;
    public $path;
    public $media_type;
    public $parent_path;

    /**
     * Used to detect whether the resource content is modified after it is retrieved from the
     * Registry. If this is set to true at the time of adding the resource back to the Registry, new
     * version will be created.
     */
    public $content_modified; //boolean

    /**
     * Normal resources have the state RegistryConstants.ACTIVE_STATE (100) Deleted resources have
     * the state RegistryConstants.DELETED_STATE (101)
     */
    public $state;

    /* hash map of properties */
    public $properties;

    public $depends_on; //String[]
    public $depended_on_by;

    //To store any kind of object
    public $content;

    public $is_directory; //Bool
    
    public $subtitle;
    
    public $title;
    
    public $directory;
    
    public $entries;
    
    public function __construct()
    {
    	$this->properties = array();
    	$this->entries = array();
    	$this->is_directory = false;
    
    }
}
?>