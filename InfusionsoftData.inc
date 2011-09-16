<?php
require_once( 'InfusionsoftService.inc' );
class InfusionsoftData extends InfusionsoftService{
    public function __construct(){
        parent::__construct();
    }
    public function query($table, $queryData, $fields = null, $customFields = null, $limit = 1000, $page = 0){
        if($fields == null){
            $fields = $this->getFieldsForTable($table);
        }

        if($customFields != null){
            $fields = array_merge($fields, $customFields);
        }

        $options = array(
            'DataService.query' => array(
                $this->key,
                $table,
                (int) $limit,
                (int) $page,
                $queryData,
                $fields
            )
        );
    		
		$results = $this->request( $options );
        $results = $this->convertDatesToStrings($results);
        return $results;
    }

    public function getFieldsForTable($table){
        $className = 'Infusionsoft' . $table;
        $object = new $className();
        return $object->getFieldsForRequest();
    }

    private function convertDatesToStrings($results){
        foreach($results as $key=> $result){
            foreach($result as $fieldName => $fieldValue){
                if(is_object($fieldValue)){
                    $results[$key][$fieldName] = date('m/d/Y', strtotime($fieldValue->iso8601));
                }
            }
        }
        return $results;
    }
}