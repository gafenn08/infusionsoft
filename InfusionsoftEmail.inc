<?php

require_once( 'InfusionsoftService' );

class InfusionSoftEmail extends InfusionsoftService {
	
	private $contact = null;
	
	/**
	 * Constructor
	 * 
	 * Pass in a InfusionsoftContact object and the properties of that 
	 * will be used automatically.  Otherwise the functions in this class 
	 * are generic so that it can still be used independently of a contact.
	 * 
	 * @param $contact Default is null
	 */
	function __construct( InfusionsoftContact &$contact = null ) {
		parent::__construct();
		
		if( $contact ) {
			$this->contact = $contact;
		}
	}
	
	/**
	 * optIn
	 * 
	 * Calls infusionsoft Emailservice.optIn for the email address passed in 
	 * or all the email addresses associated with the contact property (set 
	 * with the constructor) if $primaryOnly == false.
	 * 
	 * @param $email Default is null in which case it will look to the contact 
	 * 				 property of this class.
	 * @param $primaryOnly Default is true in which case only the first email 
	 * 					   address of the contact will be opted in.
	 */
	function optIn( $email = null, $primaryOnly = true ) {
		assert( $this->contact != null || $email != null );
		$emails = array();
		if( $email == null && $this->contact != null ) {
			if( trim( $this->contact->fields[ 'Email' ] ) != '' ) {
				$emails[] = trim( $this->contact->fields[ 'Email' ] );
			}
			if( trim( $this->contact->fields[ 'EmailAddress2' ] ) != '' ) {
				$emails[] = trim( $this->contact->fields[ 'EmailAddress2' ] );
			}
			if( trim( $this->contact->fields[ 'EmailAddress3' ] ) != '' ) {
				$emails[] = trim( $this->contact->fields[ 'EmailAddress3' ] );
			}
		}
		else {
			$emails[] = $email;
		}
		
		foreach( $emails as $email ) {
			$options = array(
				'EmailService.optIn' => array(
					$this->key,
					$email,
					''
				)
			);
			
			$return = $this->request( $options );
			
			if( $primaryOnly ) {
				break;
			}
		}
		
		return $return;
	}
}

?>