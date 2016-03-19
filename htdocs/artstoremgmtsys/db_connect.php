<?php

/**
 * A class file to connect to database
 */
class DB_CONNECT {
	//An object which represents the connection to a MySQL Server
	public $con ;
	
    // constructor
    function __construct() {
        // connecting to database
        $this->connect();
    }

    // destructor
    function __destruct() {
        // closing db connection
        $this->close();
    }

    /**
     * Function to connect with database
     */
    function connect() {
        // import database connection variables
        require_once __DIR__ . '/db_config.php';
        // Connecting to mysql database
        $this->con = mysqli_connect(DB_SERVER, DB_USER, DB_PASSWORD, DB_DATABASE);
		/* check connection */
		if (mysqli_connect_errno()) {
			printf("Connect failed: %s\n", mysqli_connect_error());
			exit();
		}
    }

    /**
     * Function to close db connection
     */
    function close() {
        // closing db connection
		if($this->con){
		mysqli_close($this->con);
		}
    }

}

?>