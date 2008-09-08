<?php
/**
 * Class DSDBExecutor
 * for database execution
 */
class DSDBExecutor {
    private $dsn;
    private $username;
    private $password;

    public function __construct($config) {
        $dsn = "";
        // setting db engine
        if($config == NULL || !is_array($config)) {
            DSUtils::error_log(__FILE__, __LINE__, 
                    "Missing configuraiton: config is not provided");
        }
        else {

            
            // user can give the dsn directly
            if(array_key_exists(DS_DSN, $config) &&
                $config[DS_DSN] != NULL) {
                $dsn = $config[DS_DSN];
            }
            else {
                if(array_key_exists(DS_DB_ENGINE, $config) &&
                    $config[DS_DB_ENGINE] != NULL) {
                    $dsn .= $config[DS_DB_ENGINE]. ":";
                }
                else {
                    DSUtils::error_log(__FILE__, __LINE__, 
                            "Missing configuraiton: database engine is not provided");
                }

                // setting db name
                if(array_key_exists(DS_DBNAME, $config) &&
                    $config[DS_DBNAME] != NULL) {
                    $dsn .= DS_DBNAME. "=". $config[DS_DBNAME]. ";";
                }
                else {
                    DSUtils::error_log(__FILE__, __LINE__, 
                            "Missing configuraiton: database name is not provided");
                }

                // setting db name
                if(array_key_exists(DS_DBHOST, $config) &&
                    $config[DS_DBHOST] != NULL) {
                    $dsn .= DS_HOST. "=". $config[DS_DBHOST];
                }
                else {
                    DSUtils::error_log(__FILE__, __LINE__, 
                            "Missing configuraiton: database host is not provided");
                }

                // setting db port
                if(array_key_exists(DS_DBPORT, $config) &&
                    $config[DS_DBPORT] != NULL) {
                    $dsn .= ":". $config[DS_DBPORT];
                }

            }
            $this->dsn = $dsn;

            // setting username
            if(array_key_exists(DS_USERNAME, $config) &&
                $config[DS_USERNAME] != NULL) {
                $this->username = $config[DS_USERNAME];
            }
            else if(array_key_exists(DS_DSN, $config) &&
                $config[DS_DSN] != NULL) {
                //user name can be in the dsn..
            }
            else {
                DSUtils::error_log(__FILE__, __LINE__, 
                        "Missing configuraiton: database username is not provided");
            }

            // setting password 
            if(array_key_exists(DS_PASSWORD, $config) &&
                $config[DS_PASSWORD] != NULL) {
                $this->password = $config[DS_PASSWORD];
            }
        }
    }

    /**
     * execute the query and return the data
     *
     * @param string $sql_query  sql query to invoke
     * @param array $params input parameter array
     * @return array of results
     */
    public function execute_query($sql_query, $params) {
        
        //create the connection..
        $dbh = $this->db_connect();
        if(!$dbh) {
            throw new WSFault("Sender", "Connection to the database failed");
        }

        //handle the query
        if($params != NULL && is_array($params) && count($params) > 0) {
            $response_info = $this->handle_prepared_stmt_query($dbh, $sql_query, $params);
        }
        else {
            $response_info = $this->handle_query($dbh, $sql_query, $params);
        }

        return $response_info;
    }
    
    /**
     * create the DBO object for the user configuration
     *
     * @return DBO Object
     */
    private function db_connect() {
        try {
            $dbh = new PDO($this->dsn, $this->username, $this->password);
        }
        catch (PDOException $e) {
            DSUtils::error_log(__FILE__, __LINE__, "Database connection failed: ".$e->getMessage().
                    "".$this->dsn. ", ".$this->username);
            throw new WSFault("Sender", $e->getMessage());
  
        }
        return $dbh;
    }

    /**
     * Handles the prepared statment
     *
     * @param DBO object $dbh
     * @param string $sql_query
     * @param array $params
     * @return array the response information
     */
    private function handle_prepared_stmt_query($dbh, $sql_query, $params) {
        
        // create the prepared statement
        if($stmt = $dbh->prepare($sql_query))
        {
            try {
                $stmt->execute($params);
            } catch(PDOExection $e) {
                DSUtils::error_log(__FILE__, __LINE__,
                        "Database execution failed: ".$e->getMessage()."");
                throw new WSFault("Sender", "Failed to access Data");
            }
            
            $results = $stmt->fetchAll();

            return $results;
        }
        else
        { 
            DSUtils::error_log(__FILE__, __LINE__,
                       "Error occured while setting the prepared statment");
            throw new WSFault("Sender", "Failed in accessing database");
        }
        return $results;
    }
 
    /**
     * Handles the direct quires which doesn't requries prepared statments
     *
     * @param PDO object $dbh
     * @return array of response information
     */
    private function handle_query($dbh, $sql_query) {

        //simple execute the query
        if($stmt= $dbh->query($sql_query)) {
            $results = $stmt->fetchAll();
        }
        else { 
            DSUtils::error_log(__FILE__, __LINE__,
                       "Error occured while setting the prepared statment: $sql_query");
            throw new WSFault("Sender", "Failed in accessing database");
        }

        return $results;
    }

    /**
     * retrieve column database from the table
     * @param string $sql_query the meta data return about
     * @param array $params input parameters
     * @return array of meta data
     */
     public function get_result_meta_info($sql_query, $params) {
 
        //create the connection..
        $dbh = $this->db_connect();
        if(!$dbh) {
            throw new WSFault("Sender", "Connection to the database failed");
        }

        // create the prepared statement
        $response_info = array();
        if($stmt = $dbh->prepare($sql_query)) {
            $stmt->execute($params);
            $column_count = $stmt->columnCount();
            for($i = 0; $i < $column_count; $i ++) {
                $meta_data = $stmt->getColumnMeta($i);
                $column_type = $meta_data[DS_DB_NATIVE_TYPE];
                $column_name = $meta_data[DS_DB_NAME];
                $response_info[$column_name] = $column_type;
            }
        }
        return $response_info;       
     }
}
?>
