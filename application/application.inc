<?php

function teacher_application_form($form, &$form_state){
    $form = array();
    $form['markup'] = array(
       '#markup' => '<p>The most <strong>FUN</strong> you will ever have teaching music.</p>',          
    );    
    $form['contact_info'] = array(
        '#type' => 'fieldset',
        '#title' => t('Contact Information'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['personal_info'] = array(
        '#type' => 'fieldset',
        '#title' => t('Personal Information'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );    
    $form['contact_info']['fname'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['contact_info']['lname'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['contact_info']['email'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['contact_info']['street_address'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['contact_info']['city'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#required' => TRUE,
        '#size' => 60,
    );
     $form['contact_info']['state'] = array(
        '#type' => 'select',
        '#title' => t('State'),
        '#required' => TRUE,
        '#options' => array('AL'=>"Alabama",'AK'=>"Alaska",'AZ'=>"Arizona",'AR'=>"Arkansas",'CA'=>"California",'CO'=>"Colorado",'CT'=>"Connecticut",'DE'=>"Delaware",'DC'=>"District Of Columbia",'FL'=>"Florida",'GA'=>"Georgia",'HI'=>"Hawaii",'ID'=>"Idaho",'IL'=>"Illinois",'IN'=>"Indiana",'IA'=>"Iowa",'KS'=>"Kansas",'KY'=>"Kentucky",'LA'=>"Louisiana",'ME'=>"Maine",'MD'=>"Maryland",'MA'=>"Massachusetts",'MI'=>"Michigan",'MN'=>"Minnesota",'MS'=>"Mississippi",'MO'=>"Missouri",'MT'=>"Montana",'NE'=>"Nebraska",'NV'=>"Nevada",'NH'=>"New Hampshire",'NJ'=>"New Jersey",'NM'=>"New Mexico",'NY'=>"New York",'NC'=>"North Carolina",'ND'=>"North Dakota",'OH'=>"Ohio",'OK'=>"Oklahoma",'OR'=>"Oregon",'PA'=>"Pennsylvania",'RI'=>"Rhode Island",'SC'=>"South Carolina",'SD'=>"South Dakota",'TN'=>"Tennessee",'TX'=>"Texas",'UT'=>"Utah",'VT'=>"Vermont",'VA'=>"Virginia",'WA'=>"Washington",'WV'=>"West Virginia",'WI'=>"Wisconsin", 'WY'=>"Wyoming"),
    );
    $form['contact_info']['zip'] = array(
        '#type' => 'textfield',
        '#title' => t('Zip'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['contact_info']['phone'] = array(
        '#type' => 'textfield',
        '#title' => t('Phone Number'),
        '#required' => TRUE,
        '#size' => 60,
    );
    $form['personal_info']['available_time'] = array(
        '#type' => 'textfield',
        '#title' => t('Optimal time/day to call'),
        '#required' => TRUE,
        '#size' => 60,
    );
     $form['personal_info']['music_experience'] = array(
        '#type' => 'textarea',
        '#title' => t('Please list your music experience'),
        '#required' => TRUE,
        '#resizable' => FALSE,
    );   
    $form['personal_info']['teaching_experience'] = array(
        '#type' => 'textarea',
        '#title' => t('Optimal time/day to call'),
        '#required' => TRUE,
        '#resizable' => FALSE,
    );
    $form['personal_info']['about_teacher'] = array(
        '#type' => 'textarea',
        '#title' => t("Tell us a little about your family (married, children etc.)"),
        '#required' => TRUE,
        '#resizable' => FALSE,
    );
    $form['personal_info']['hear_about_lpm'] = array(
        '#type' => 'textarea',
        '#title' => t("How did you hear about Let's Play Music?"),
        '#required' => TRUE,
        '#resizable' => FALSE,
    );
    $form['personal_info']['why_lpm'] = array(
        '#type' => 'textarea',
        '#title' => t("What about Let's Play Music is particularly appealing to you?"),
        '#required' => TRUE,
        '#resizable' => FALSE,
    );
    $form['personal_info']['mugshot'] = array(
        '#title' => t('Please upload a photo of yourself!'),
        '#type' => 'managed_file',
        '#upload_validators' => array('file_validate_extensions' => array('jpeg jpg png gif')),
        '#upload_location' => 'public://infusionsoft/mugshot',
        '#progress_indicator' => 'throbber',    
        '#progress_message' => 'One moment while we save your file...',
        '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif'),

    );       
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit'),
        '#submit' => array('teacher_application_form_submit'),
    );
    return $form;
}

function teacher_application_form_submit($form, &$form_state){
        
    drupal_set_message('Submitted Successfully.');
}