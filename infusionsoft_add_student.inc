<?php
require_once('infusionsoft_util.inc');
function infusionsoft_add_student_parent($form, &$form_state) {

  // Display page 2 if $form_state['page_num'] == 1
  if (!empty($form_state['page_num']) && $form_state['page_num'] == 2) {
    return infusionsoft_add_student_student($form, $form_state);
  }

  // Otherwise build page 1.
  $form_state['page_num'] = 1;

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Before you add a new student please add their parents information'),
  );
  $form['Id'] = array(
    '#type' => 'hidden',
    '#value' => '',
  );
  $form['PFirstName'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent first name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['PFirstName']) ? $form_state['values']['PFirstName'] : '',
  );
  $form['PLastName'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent last name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['PLastName']) ? $form_state['values']['PLastName'] : '',
  );
  $form['Email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['Email']) ? $form_state['values']['Email'] : '',
  );
  $form['Phone1'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone Number'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['Phone1']) ? $form_state['values']['Phone1'] : '',
  );  
  $form['StreetAddress1'] = array(
    '#type' => 'textfield',    
    '#title' => "Street Address",
    '#size' => 60,
    '#required' => TRUE,    
    '#default_value' => !empty($form_state['values']['StreetAddress1']) ? $form_state['values']['StreetAddress1'] : '',
  );
  $form['City'] = array(
    '#type' => 'textfield',
    '#title' => "City",
    '#size' => 60,
    '#required' => TRUE,    
    '#default_value' => !empty($form_state['values']['City']) ? $form_state['values']['City'] : '',
  );
  $form['State'] = array(
    '#type' => 'textfield',
    '#title' => "State",
    '#size' => 60,
    '#required' => TRUE,    
    '#default_value' => !empty($form_state['values']['State']) ? $form_state['values']['State'] : '',
  );
  $form['PostalCode'] = array(
    '#type' => 'textfield',
    '#title' => "Zip",
    '#size' => 60,
    '#required' => TRUE,    
    '#default_value' => !empty($form_state['values']['PostalCode']) ? $form_state['values']['PostalCode'] : '',
  );   
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => 'Next >>',
    '#submit' => array('infusionsoft_add_student_next_submit'),
    '#validate' => array('infusionsoft_add_student_next_validate'),
  );
  
  return $form;
}

/**
 * Validate handler for the next button on first page.
 */
function infusionsoft_add_student_next_validate($form, &$form_state) {
  $email = $form_state['values']['Email'];
  if (!valid_email_address($email)) {
    form_set_error('Email', t('You Must Enter a valid E-Mail address'));
  }
}

/**
 * Submit handler for parent contact record form next button.
 *
 * Capture the values from page one and store them away so they can be used
 * at final submit time.
 */
function infusionsoft_add_student_next_submit($form, &$form_state) {

  // Values are saved for each page.
  // to carry forward to subsequent pages in the form.
  // and we tell FAPI to rebuild the form.
  $form_state['page_values'][1] = $form_state['values'];

  if (!empty($form_state['page_values'][2])) {
    $form_state['values'] = $form_state['page_values'][2];
  }

  // When form rebuilds, it will look at this to figure which page to build.
  $form_state['page_num'] = 2;
  $form_state['rebuild'] = TRUE;
}



/**
 * Returns the form for the student contact.
 */
function infusionsoft_add_student_student($form, &$form_state) {
    $form['description'] = array(
	'#type' => 'item',
	'#title' => t('Add New Student Information'),
    );
    $form['Id'] = array(
	'#type' => 'hidden',
	'#value' => '',
  );
    $form['SFirstName'] = array(
	'#type' => 'textfield',
	'#title' => t('First name'),
	'#size' => 60,
	'#required' => TRUE,
	'#default_value' => !empty($form_state['values']['SFirstName']) ? $form_state['values']['SFirstName'] : '',
    );
    $form['SLastName'] = array(
	'#type' => 'textfield',
	'#title' => t('Last name'),
	'#size' => 60,
	'#required' => TRUE,
	'#default_value' => !empty($form_state['values']['SLastName']) ? $form_state['values']['SLastName'] : '',
    );
    $form['Birthday'] = array(
	'#type' => 'date',
	'#title' => t('Birthday'),
	'#required' => TRUE,
    );    
    $form['_Gender0'] = array(
        '#type' => 'radios',
        '#title' => t('Gender'),
        '#required' => TRUE,
	'#default_value' => variable_get('_Gender0', 0),
        '#options' => array('Male', 'Female'),
    );  
    $form['submit'] = array(
	'#type' => 'submit',
	'#value' => t('Submit'),
	'#submit' => array('infusionsoft_add_student_submit'),
    );
    $form['back'] = array(
	'#type' => 'submit',
	'#value' => t('<< Back'),
	'#submit' => array('infusionsoft_add_student_back'),
	'#limit_validation_errors' => array(),
    );
  return $form;
}




/**
 * Back button submit handler.
 *
 */
function infusionsoft_add_student_back($form, &$form_state) {
  $form_state['values'] = $form_state['page_values'][1];
  $form_state['page_num'] = 1;
  $form_state['rebuild'] = TRUE;
}

/**
 * The final submit handler.
 *
 */
function infusionsoft_add_student_submit($form, &$form_state) {
    global $user;
    $user_fields = user_load($user->uid);
    $fullname = $user_fields->field_user_full_name['und']['0']['value'];
    $birthday = $form_state['values']['Birthday'];
    $page_one_values = $form_state['page_values'][1];
    $infusionsoftContact = new InfusionsoftContact($page_one_values['Id']);    
    $infusionsoftContact->fields['Id'] = $page_one_values['Id'];
    $infusionsoftContact->fields['FirstName'] = $page_one_values['PFirstName'];
    $infusionsoftContact->fields['LastName'] = $page_one_values['PLastName'];
    $infusionsoftContact->fields['Email'] = $page_one_values['Email'];
    $infusionsoftContact->fields['Phone1'] = $page_one_values['Phone1'];
    $infusionsoftContact->fields['StreetAddress1'] = $page_one_values['StreetAddress1'];
    $infusionsoftContact->fields['City'] = $page_one_values['City'];
    $infusionsoftContact->fields['State'] = $page_one_values['State'];
    $infusionsoftContact->fields['PostalCode']	= $page_one_values['PostalCode'];
    $infusionsoftContact->fields['_TeacherID'] = (string)get_current_teacher_id(); 
    $infusionsoftContact->fields['_ContactType0'] = 'Parent';
    $infusionsoftContact->fields['_Teacher'] = $fullname;
    $parent_id = $infusionsoftContact->save();
    
    $infusionsoftContact = new InfusionsoftContact($form_state['values']['Id']);
    $infusionsoftContact->fields['FirstName'] = $form_state['values']['SFirstName'];
    $infusionsoftContact->fields['LastName'] = $form_state['values']['SLastName'];
    $infusionsoftContact->fields['Birthday'] = $birthday['month'] . '/' . $birthday['day'] . '/' . $birthday['year'];
    $infusionsoftContact->fields['_Gender0'] = ($form_state['values']['_Gender0'] == 0 ? "Male" : "Female");
    $infusionsoftContact->fields['_Parent'] =  $page_one_values['PFirstName'] . ' ' .$page_one_values['PLastName'];
    $infusionsoftContact->fields['_ParentID'] = (string)$parent_id;
    $infusionsoftContact->fields['_TeacherID'] = (string)get_current_teacher_id();
    $infusionsoftContact->fields['_Teacher'] = $fullname;
    $infusionsoftContact->fields['_StudentLevel'] = "Level One";
    $infusionsoftContact->fields['_StudentStatus'] = "In Class";
    $infusionsoftContact->fields['_ContactType0'] = "Student";
    $infusionsoftContact->save();
    
    $form_state['redirect'] = 'infusionsoft'; // Redirects the user to infusionsoft.
    drupal_set_message("Thanks " . $fullname . ", " . $page_one_values['PFirstName'] . ' ' .$page_one_values['PLastName'] . '(Parent) and ' . $form_state['values']['SFirstName'] . ' ' .$form_state['values']['SLastName'] . '(Student) have been saved!');
}