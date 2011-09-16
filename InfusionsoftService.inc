<?php

/**
 * Base class for interfacing with Infusionsoft.
 * Handles all communication via the xml/rpc Drupal module.
 * 
 * @author Jim McGowen
 *
 */
class InfusionsoftService {
	
	// The infusionsoft url, set by the constructor
	protected $server;
	
	//The infusionsoft key, set by the constructor
	protected $key;
	
	/**
	 * Constructor
	 * 
	 */
	function __construct() {
		// Get the server url and key from the infusionsoft db
		$server = db_query( "SELECT appname FROM {infusionsoft}" );
		if( $server !== false ) {
			$this->server = $server->fetchField();
		}
		$key = db_query( "SELECT apikey FROM {infusionsoft}" );
		if( $key !== false ) {
			$this->key = $key->fetchField();
		}
	}
	
	/**
	 * Request
	 * 
	 * Makes an xml/rpc request to Infusionsoft.
	 * 
	 * @param $options Options for the xmlrpc function.
	 */
	public function request( $options ) {
		$result = xmlrpc( $this->server, $options );
		if( $result == false ) {
			// Indicate the error somehow?
			drupal_set_message(xmlrpc_error_msg());
		}
		return $result ;
	}
}

?>