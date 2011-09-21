<?php 
require_once('infusionsoft_util.inc');

/* This function creates the form to edit teacher contact records.*/
function infusionsoft_teacher_form($form, &$form_state){
    global $user;
    $contact_record = new InfusionsoftContact();    
    $contact = $contact_record->loadContactByEmail($user->mail);
    $fields = $contact_record->fields;

    $form = array();
    $form['teacher']= array(
    	'#type' => 'fieldset',
    	'#title' => 'Your Information',
    	'#description' => 'Change your personal information.',
    	'#collapsible' => TRUE,
    	'#collapsed' => TRUE,
    );
    $form['teacher']['Id'] = array(
    	'#type' => 'hidden',
    	'#value' => $fields['Id'],
  	);
  	
  	$form['teacher']['FirstName'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('First name'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['FirstName'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['LastName'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Last name'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['LastName'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['Email'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('E-Mail'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['Email'],
  	  	'#size' => 60,
  	);  
  	$form['teacher']['StreetAddress1'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Street Address'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['StreetAddress1'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['StreetAddress2'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Additional Street Address'),
  	  	'#required' => FALSE,
  	  	'#default_value' => $fields['StreetAddress2'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['City'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('City'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['City'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['State'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('State'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['State'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['PostalCode'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Postal Code'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['PostalCode'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['Phone1'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Home Phone'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['Phone1'],
  	  	'#size' => 60,
  	);
  	$form['teacher']['Phone2'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Cell Phone'),
  	  	'#required' => FALSE,
  	  	'#default_value' => $fields['Phone2'],
  	  	'#size' => 60,
  	);
    $form['teacher']['submit'] = array(
        '#type' => 'submit',
        '#value' => t("Update"),
        '#submit' => array('infusionsoft_teacher_form_submit'),
    );


 
    
	//drupal_set_message(print_r($contact_record->fields, TRUE));
	return $form;
    }


/* This function creates the form to edit teacher contact records.*/
function infusionsoft_parent_form($form, &$form_state, $id){
        
    $contact_record = new InfusionsoftContact();
    $contact = $contact_record->loadContactByID($id);
    $fields = $contact_record->fields;
   
    $form = array();

    $form['parent']= array(
    	'#type' => 'fieldset',
    	'#title' => 'Parent Information',
    	'#collapsible' => FALSE,
    	'#collapsed' => FALSE,
    );
    $form['parent']['Id'] = array(
    	'#type' => 'hidden',
    	'#value' => $fields['Id'],
  	);
  	
  	$form['parent']['FirstName'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('First name'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['FirstName'],
  	  	'#size' => 60,
  	);
  	$form['parent']['LastName'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Last name'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['LastName'],
  	  	'#size' => 60,
  	);
  	$form['parent']['Email'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('E-Mail'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['Email'],
  	  	'#size' => 60,
  	);  
  	$form['parent']['StreetAddress1'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Street Address'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['StreetAddress1'],
  	  	'#size' => 60,
  	);
  	$form['parent']['StreetAddress2'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Additional Street Address'),
  	  	'#required' => FALSE,
  	  	'#default_value' => $fields['StreetAddress2'],
  	  	'#size' => 60,
  	);
  	$form['parent']['City'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('City'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['City'],
  	  	'#size' => 60,
  	);
  	$form['parent']['State'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('State'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['State'],
  	  	'#size' => 60,
  	);
  	$form['parent']['PostalCode'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Postal Code'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['PostalCode'],
  	  	'#size' => 60,
  	);
  	$form['parent']['Phone1'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Home Phone'),
  	  	'#required' => TRUE,
  	  	'#default_value' => $fields['Phone1'],
  	  	'#size' => 60,
  	);
  	$form['parent']['Phone2'] = array(
  	  	'#type' => 'textfield',
  	  	'#title' => t('Cell Phone'),
  	  	'#required' => FALSE,
  	  	'#default_value' => $fields['Phone2'],
  	  	'#size' => 60,
  	);

    $form['parent']['submit'] = array(
         '#type' => 'submit',
         '#value' => t("Update"),
         '#submit' => array('infusionsoft_parent_form_submit'),
    );
    $form['parent']['cancel'] = array(
         '#markup' => l(t('Back to Roster'), 'infusionsoft', array('attributes' => array('class' => array('button')))),
    );

	return $form;
}

function infusionsoft_student_form($form, &$form_state, $id){
    
    $contact_record = new InfusionsoftContact();
    $contact = $contact_record->loadContactByID($id);
    $fields = $contact_record->fields;
    $year = $fields['Birthday']->year;
    $month = $fields['Birthday']->month;
  	$day = $fields['Birthday']->day;
   // dsm($fields['Birthday']);
    $date = (isset($fields['Birthday']) ? array('year' => (int)$year, 'month' => (int)$month, 'day' => (int)$day) : '');
    
    $gender = ($fields['_Gender0'] == 'Male' ? 0 : 1);
    $form = array();   
    $form['student'] = array(
    	'#type' => 'fieldset',
    	'#title' => 'Student Information',
    	'#collapsible' => FALSE,
    	'#collapsed' => FALSE,
    );
    $form['student']['Id'] = array(
        '#type' => 'hidden',
        '#value' => $fields['Id'],
    );    
    $form['student']['FirstName'] = array(
        '#type' => 'textfield',
        '#title' => t('First name'),
        '#required' => TRUE,
        '#default_value' => $fields['FirstName'],
        '#size' => 60,
    );
    $form['student']['LastName'] = array(
        '#type' => 'textfield',
        '#title' => t('Last name'),
        '#required' => TRUE,
        '#default_value' => $fields['LastName'],
    );
    $form['student']['Birthday'] = array(
        '#type' => 'date',
        '#title' => t('Birthday'),
        '#required' => TRUE,
        '#default_value' => $date,
    );
    $form['student']['_Gender0'] = array(
        '#type' => 'radios',
        '#title' => t('Gender'),
        '#required' => TRUE,
	'#default_value' => $gender,
        '#options' => array('Male', 'Female'),
    );      
    $form['student']['_StudentLevel'] = array(
        '#type' => 'radios',
        '#title' => t('Level'),
        '#required' => TRUE,
        '#default_value' => variable_get('_StudentLevel', $fields['_StudentLevel']),
        '#options' => array('Level One' => 'Level One', 'Level Two' => 'Level Two', 'Level Three' => 'Level Three', 'Graduated' => 'Graduated',),
    );
    $form['student']['_GraduationYear'] = array(
        '#type' => 'textfield',
        '#title' => t('Graduation Year'),
        '#required' => FALSE,
        '#default_value' => $fields['_GraduationYear'],
        '#states' => array(
            'visible' => array(   // action to take.
            ':input[name=_StudentLevel]' => array('value' => t('Graduated')),
      ),
     ),
    );    
    $form['student']['_StudentStatus'] = array(
        '#type' => 'radios',
        '#title' => t('Status'),
        '#required' => TRUE,
        '#default_value' => variable_get('_StudentLevel', $fields['_StudentStatus']),
        '#options' => array('In Class' => 'In Class', 'Dropped' => 'Dropped', 'Graduated' => 'Graduated'),
    );
    $form['student']['_ReasonforDrop'] = array(
        '#type' => 'textfield',
        '#title' => t('Reason For Drop'),
        '#required' => FALSE,
        '#default_value' => $fields['_ReasonforDrop'],
        '#states' => array(
            'visible' => array(   // action to take.
            ':input[name=_StudentStatus]' => array('value' => t('Dropped')),
      ),
     ),
    );      
    
    $form['student']['submit'] = array(
        '#type' => 'submit',
        '#value' => t("Update"),
        '#submit' => array('infusionsoft_student_form_submit'),
    );
    $form['student']['cancel'] = array(
        '#markup' => l(t('Back to Roster'), 'infusionsoft', array('attributes' => array('class' => array('button')))),
    );

    return $form;
}

function infusionsoft_teacher_form_submit($form, &$form_state){
    $infusionsoftContact = new InfusionsoftContact($form_state['values']['Id']);
    $saveFields = array('Id', 'FirstName', 'LastName', 'Email', 'StreetAddress1', 'Address2', 'Phone1', 'City', 'State', 'PostalCode', 'Country', 'Phone2', 'StreetAddress2');
    foreach($saveFields as $fieldName){
        if(isset($form_state['values'][$fieldName])){
            $infusionsoftContact->fields[$fieldName] = $form_state['values'][$fieldName];
        }
    }
    $id = $infusionsoftContact->save();
    drupal_set_message("Your information has been updated!");
}
function infusionsoft_student_form_submit($form, &$form_state){
    $birthday = $form_state['values']['Birthday'];
    $infusionsoftContact = new InfusionsoftContact($form_state['values']['Id']);
    $saveFields = array('Id','FirstName', 'LastName', '_StudentLevel', '_StudentStatus', '_ReasonforDrop', '_GraduationYear');
    foreach($saveFields as $fieldName){
        if(isset($form_state['values'][$fieldName])){
            $infusionsoftContact->fields[$fieldName] = $form_state['values'][$fieldName];
        }
    }
    $infusionsoftContact->fields['Birthday'] = $birthday['month'] . '/' . $birthday['day'] . '/' . $birthday['year'];
    $infusionsoftContact->fields['_Gender0'] = ($form_state['values']['_Gender0'] == 0 ? "Male" : "Female");
    $infusionsoftContact->save();
    drupal_set_message($form_state['values']['FirstName'] . ' ' . $form_state['values']['LastName'] ."'s information has been updated");
}
function infusionsoft_parent_form_submit($form, &$form_state){
    $infusionsoftContact = new InfusionsoftContact($form_state['values']['Id']);
    $saveFields = array('Id', 'FirstName', 'LastName', 'Email', 'StreetAddress1', 'Address2', 'Phone1', 'City', 'State', 'PostalCode', 'Country', 'Phone2', 'StreetAddress2');
    foreach($saveFields as $fieldName){
        if(isset($form_state['values'][$fieldName])){
            $infusionsoftContact->fields[$fieldName] = $form_state['values'][$fieldName];
        }
    }
    $infusionsoftContact->save();
    drupal_set_message($form_state['values']['FirstName'] . ' ' . $form_state['values']['LastName'] ."'s information has been updated");
}

function infusionsoft_dashboard_redirect(){
    drupal_goto('infusionsoft/dashboard');
}