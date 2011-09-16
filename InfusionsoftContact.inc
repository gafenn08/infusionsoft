<?php 

require_once( 'InfusionsoftService.inc' );

/**
 * InfusionsoftContact
 * 
 * Class to represent a single contact from Infusionsoft.
 * 
 * @author Jim McGowen
 *
 */
class InfusionsoftContact extends InfusionsoftService {
	
	// These are all the contact record fields defined by Infusionsoft.
	public $fields = array(
		//'AccountId' => '',
		'Address1Type' => '',
		'Address2Street1' => '',
		'Address2Street2' => '',
		'Address2Type' => '',
		'Address3Street1' => '',
		'Address3Street2' => '',
		'Address3Type' => '',
		'Anniversary' => '',
		'AssistantName' => '',
		'AssistantPhone' => '',
		'BillingInformation' => '',
		'Birthday' => '',
		'City' => '',
		'City2' => '',
		'City3' => '',
		'Company' => '',
		'CompanyID' => '',
		'ContactNotes' => '',
		'ContactType' => '',
		'Country' => '',
		'Country2' => '',
		'Country3' => '',
		'CreatedBy' => '',
		'DateCreated' => '',
		'Email' => '',
		'EmailAddress2' => '',
		'EmailAddress3' => '',
		'Fax1' => '',
		'Fax1Type' => '',
		'Fax2' => '',
		'Fax2Type' => '',
		'FirstName' => '',
		'Groups' => '',
		'Id' => '',
		'JobTitle' => '',
		'LastName' => '',
		'LastUpdated' => '',
		'LastUpdatedBy' => '',
		'LeadSourceId' => '',
		//'Leadsource' => '',
		'MiddleName' => '',
		'Nickname' => '',
		'OwnerID' => '',
		'Password' => '',
		'Phone1' => '',
		'Phone1Ext' => '',
		'Phone1Type' => '',
		'Phone2' => '',
		'Phone2Ext' => '',
		'Phone2Type' => '',
		'Phone3' => '',
		'Phone3Ext' => '',
		'Phone3Type' => '',
		'Phone4' => '',
		'Phone4Ext' => '',
		'Phone4Type' => '',
		'Phone5' => '',
		'Phone5Ext' => '',
		'Phone5Type' => '',
		'PostalCode' => '',
		'PostalCode2' => '',
		'PostalCode3' => '',
		'ReferralCode' => '',
		'SpouseName' => '',
		'State' => '',
		'State2' => '',
		'State3' => '',
		'StreetAddress1' => '',
		'StreetAddress2' => '',
		'Suffix' => '',
		'Title' => '',
		'Username' => '',
		'Validated' => '',
		'Website' => '',
		'ZipFour1' => '',
		'ZipFour2' => '',
		'ZipFour3' => '',
		'_Gender0' => '',
		'_StudentStatus' => '',
		'_ReasonforDrop' => '',
		'_StudentLevel' => '',
		'_GraduationYear' => '',
	);
	
	public $contactLoaded = false;
	
	/**
	 * Constructor
	 * 
	 * 
	 * 
	 * @param unknown_type $id ID of the contact to load
	 */
	function __construct( $id = null ) {
		parent::__construct();
		
		if( $id ) {
			$this->loadContactByID( $id );
		}
	}
	
	/**
	 * loadContactByID
	 * 
	 * Loads a contact from Infusionsoft givin the contact Id.
	 * 
	 * @param $id ID of the contact to load
	 */
	public function loadContactByID( $id ) {
		$fields = $this->getFieldsForRequest();
		$options = array(
			'ContactService.load' => array(
				$this->key,
				(int) $id,
				$fields
			)
		);
		
		$result = $this->request( $options );
		if( $result !== false ) {
			$this->loadFieldsFromResult( $result );
			
			// Success
			$this->contactLoaded = true;
			return true;
		}
		
		// Todo: only works with the devel module enabled.
		//       Will it be ignored otherwise or throw an exception?
		drupal_set_message( "Contact not found (id: $id)"  );
		
		// Contact was not loaded
		$this->contactLoaded = false;
		return false;
	}
	
	/**
	 * loadContactByEmail
	 * 
	 * Loads a contact from Infusionsoft given an email address.
	 * If multiple contacts with the same email are found, only 
	 * the first contact is loaded.
	 * 
	 * @param unknown_type $email
	 */
	public function loadContactByEmail( $email ) {
		$fields = $this->getFieldsForRequest();
		$options = array(
			'ContactService.findByEmail' => array(
				$this->key,
				$email,
				$fields
			)
		);
		
		$result = $this->request( $options );
		//dsm( print_r( $result[ 0 ], true ) );
		if( $result !== false ) {
			
			$this->loadFieldsFromResult( $result[ 0 ] );
			
			// Success
			$this->contactLoaded = true;
			return true;
		}
		
		// Todo: only works with the devel module enabled.
		//       Will it be ignored otherwise or throw an exception?
		drupal_set_message( "Contact not found (email: $email)"  );
		
		// Contact was not loaded
		$this->contactLoaded = false;
		return false;
	}

    	/**
	 * loadContactsByFields
	 *
	 * Loads a contact from Infusionsoft given an email address.
	 * If multiple contacts with the same email are found, only
	 * the first contact is loaded.
	 *
	 * @param unknown_type $email
	 */
	public function loadContactsByFields( $email ) {
		$fields = $this->getFieldsForRequest();
		$options = array(
			'ContactService.query' => array(
				$this->key,
				$email,
				$fields
			)
		);

		$result = $this->request( $options );
		//dsm( print_r( $result[ 0 ], true ) );
		if( $result !== false ) {
			$this->loadFieldsFromResult( $result[ 0 ] );

			// Success
			$this->contactLoaded = true;
			return true;
		}

		// Todo: only works with the devel module enabled.
		//       Will it be ignored otherwise or throw an exception?
		dsm( "Contact not found (email: $email)"  );

		// Contact was not loaded
		$this->contactLoaded = false;
		return false;
	}

	/**
	 * save
	 * 
	 * Adds or updates this contact with Infusionsoft.
	 * 
	 * returns true if successfull, false if not.
	 */
	public function save() {
		if( $this->fields[ 'Id' ] !== '' ) {
        // Check to see if the contact already exists
            return $this->update();
        }
        else {
            return $this->add();
        }
	}
	
	/**
	 * add
	 * 
	 * Adds the contact to Infusionsoft.  Infusionsoft allows duplicates 
	 * so make sure you want to add before calling this.  A safer method 
	 * is to call the save function which will check to see if the contact
	 * exists first and update it if it does.  The contact is automatically 
	 * opted in for the primary email only.
	 */
	public function add() {
		$options = array(
			'ContactService.add' => array(
				$this->key,
				$this->fields
			)
		);
		
		$return = $this->request( $options );
		
		// Automatically opt in for emails
		//$email = new InfusionSoftEmail( $this );
		//$email->optIn();
		
		return $return;
	}
	
	/**
	 * update
	 * 
	 * Updates the contact with Infusionsoft.
	 */
	public function update() {
		$options = array(
			'ContactService.update' => array(
				$this->key,
				(int) $this->fields[ 'Id' ],
				$this->fields
			)
		);
		
		$result = $this->request( $options );
		assert( $result == $this->fields[ 'Id' ] );
		
		return $result;
	}
	
	/**
	 * getFieldsForRequest
	 * 
	 * Helper function that creates a non-associative array of 
	 * fields from the $this->fields property. This is needed for 
	 * Infusionsoft contact requests.
	 * 
	 */
	public function getFieldsForRequest() {
		$fields = array();
		foreach( $this->fields as $key => $value ) {
			$fields[] = $key;
		}
		return $fields;
	}
	
	/**
	 * loadFieldsFromResult
	 * 
	 * Populates the fields property from the result array from 
	 * Infusionsoft.
	 * 
	 * @param $result
	 */
	private function loadFieldsFromResult( $result ) {
		foreach( $result as $key => $value ) {
			if( array_key_exists( $key, $this->fields ) ) {
				$this->fields[ $key ] = $value;
			}
		}
	}
}

?>