<?php
function get_current_teacher_id(){
	global $user;
	$contact_record = new InfusionsoftContact();
	$contact = $contact_record->loadContactByEmail($user->mail);
	$fields = $contact_record->fields;
	return $fields['Id'];
}