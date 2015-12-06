<?php
include('../contentManagementInclude/dbdata.inc');

class Page
{

  // TABLE pages
  // id         
  // pageURL
  // displayOrder   
  // navTitle
  // navSubtitle
  // pageTitle  
  // pageContent
  // pageHeadCustomize
  
  public $id = null;
  public $pageURL = null;
  public $displayOrder = null;
  public $navTitle = null;
  public $navSubtitle = null;
  public $pageTitle = null;
  public $pageContent = null;
  public $pageHeadCustomize = null;
  public $useJQuery = null;
  public $useFancyBox = null;
  public $useFancyBoxGallery = null;
  
  public function __construct($data=array())
  {
    if (isset($data['id'])) $this->id = (int) $data['id'];
    if (isset($data['pageURL'])) $this->pageURL = $data['pageURL'];
    if (isset($data['displayOrder'])) $this->displayOrder = (int) $data['displayOrder'];
    if (isset($data['navTitle'])) $this->navTitle = $data['navTitle'];
    if (isset($data['navSubtitle'])) $this->navSubtitle = $data['navSubtitle'];
    if (isset($data['pageTitle'])) $this->pageTitle = $data['pageTitle'];
    if (isset($data['pageContent'])) $this->pageContent = $data['pageContent'];
    if (isset($data['pageHeadCustomize'])) $this->pageHeadCustomize = $data['pageHeadCustomize'];
    if (isset($data['useJQuery'])) $this->useJQuery = $data['useJQuery'];
    if (isset($data['useFancyBox'])) $this->useFancyBox = $data['useFancyBox'];
    if (isset($data['useFancyBoxGallery'])) $this->useFancyBoxGallery = $data['useFancyBoxGallery'];
  }
  
  public static function getByID($id)
  {
    $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
    $sqlString = 'SELECT * FROM pages WHERE id = :id';
    $st = $conn->prepare($sqlString);
    $st->bindValue(':id', $id, PDO::PARAM_INT);
    $st->execute();
    $row = $st->fetch();
    $conn = null;
    if ($row)
      return new Page($row);
  }
  
  public static function getByURL($url)
  {
    $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
    $sqlString = 'SELECT * FROM pages WHERE pageURL = :url';
    $st = $conn->prepare($sqlString);
    $st->bindValue(':url', $url, PDO::PARAM_STR);
    $st->execute();
    $row = $st->fetch();
    $conn = null;
    if ($row)
      return new Page($row);
  }
  
  public static function getList($numRows = 1000000, $order = 'displayOrder ASC')
  {
    $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
    $sqlString = 'select SQL_CALC_FOUND_ROWS * from pages ORDER BY ' . mysql_escape_string($order) . ' LIMIT :numRows';
    $st = $conn->prepare($sqlString);
    $st->bindValue(':numRows', $numRows, PDO::PARAM_INT);
    $st->execute();
    $list = array();
    while ($row = $st->fetch())
    {
      $page = new Page($row);
      $list[] = $page;
    }
    $sqlString = 'SELECT FOUND_ROWS() AS totalRows';
    $totalRows = $conn->query($sqlString)->fetch();
    $conn = null;
    
    return array('results' => $list, 'totalRows' => $totalRows[0]);
  }
  
  public function storeFormValues($params)
  {
    //set up $params for checkboxes
    if (isset($params['useJQuery']) && $params['useJQuery'] == 'on')
      $params['useJQuery'] = 1;
    else
      $params['useJQuery'] = 0;
    if (isset($params['useFancyBox']) && $params['useFancyBox'] == 'on')
      $params['useFancyBox'] = 1;
    else
      $params['useFancyBox'] = 0;
    if (isset($params['useFancyBoxGallery']) && $params['useFancyBoxGallery'] == 'on')
      $params['useFancyBoxGallery'] = 1;
    else
      $params['useFancyBoxGallery'] = 0;
    
    //use constructor to store array
    $this->__construct($params);
  }
  
  // TABLE pages
  // id         
  // pageURL
  // displayOrder   
  // navTitle
  // navSubtitle
  // pageTitle  
  // pageContent
  // pageHeadCustomize
  
  //use the values currently in an instantiated copy of this class to insert into the database
  //won't work if the property $id has already been set
  public function insert()
  {
    if (is_null($this->id))
    {
      $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
      $sqlString = 'INSERT INTO pages (pageURL, displayOrder, navTitle, navSubtitle, pageTitle, pageContent, pageHeadCustomize, useJQuery, useFancyBox, useFancyBoxGallery) VALUES (:pageURL, :displayOrder, :navTitle, :navSubtitle, :pageTitle, :pageContent, :pageHeadCustomize, :useJQuery, :useFancyBox, :useFancyBoxGallery)';
      $st = $conn->prepare($sqlString);
      $st->bindValue(':pageURL', $this->pageURL, PDO::PARAM_STR);
      $st->bindValue(':displayOrder', $this->displayOrder, PDO::PARAM_INT);
      $st->bindValue(':navTitle', $this->navTitle, PDO::PARAM_STR);
      $st->bindValue(':navSubtitle', $this->navSubtitle, PDO::PARAM_STR);
      $st->bindValue(':pageTitle', $this->pageTitle, PDO::PARAM_STR);
      $st->bindValue(':pageContent', $this->pageContent, PDO::PARAM_STR);
      $st->bindValue(':pageHeadCustomize', $this->pageHeadCustomize, PDO::PARAM_STR);
      $st->bindValue(':useJQuery', $this->useJQuery, PDO::PARAM_STR);
      $st->bindValue(':useFancyBox', $this->useFancyBox, PDO::PARAM_STR);
      $st->bindValue(':useFancyBoxGallery', $this->useFancyBoxGallery, PDO::PARAM_STR);
      $st->execute();
      $this->id = $conn->lastInsertId();
      $conn = null;
    }
    else
    {
      //error: something already set this object's ID. use $this->update() instead
    }
  }

  //use the values currently in an instantiated copy of this class to insert into the database
  //will only work if the property $id has already been set
  public function update()
  {
    if (!is_null($this->id))
    {
      $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
      $sqlString = 'UPDATE pages SET pageURL=:pageURL, displayOrder=:displayOrder, navTitle=:navTitle, navSubtitle=:navSubtitle, pageTitle=:pageTitle, pageContent=:pageContent, pageHeadCustomize=:pageHeadCustomize, useJQuery=:useJQuery, useFancyBox=:useFancyBox, useFancyBoxGallery=:useFancyBoxGallery WHERE id = :id';
      $st = $conn->prepare($sqlString);
      $st->bindValue(':pageURL', $this->pageURL, PDO::PARAM_STR);
      $st->bindValue(':displayOrder', $this->displayOrder, PDO::PARAM_INT);
      $st->bindValue(':navTitle', $this->navTitle, PDO::PARAM_STR);
      $st->bindValue(':navSubtitle', $this->navSubtitle, PDO::PARAM_STR);
      $st->bindValue(':pageTitle', $this->pageTitle, PDO::PARAM_STR);
      $st->bindValue(':pageContent', $this->pageContent, PDO::PARAM_STR);
      $st->bindValue(':pageHeadCustomize', $this->pageHeadCustomize, PDO::PARAM_STR);
      $st->bindValue(':useJQuery', $this->useJQuery, PDO::PARAM_STR);
      $st->bindValue(':useFancyBox', $this->useFancyBox, PDO::PARAM_STR);
      $st->bindValue(':useFancyBoxGallery', $this->useFancyBoxGallery, PDO::PARAM_STR);
      $st->bindValue(':id', $this->id, PDO::PARAM_INT);
      $st->execute();
      $conn = null;
    }
    else
    {
      //error: $this->id was not set.
    }
  }
  
  //deletes $this->id from the database
  //will only work if the property $id has already been set
  public function delete()
  {
    if (!is_null($this->id))
    {
      $conn = new PDO(DB_DSN, DB_USER, DB_PASSWORD);
      $sqlString = 'DELETE FROM pages WHERE id = :id LIMIT 1';
      $st = $conn->prepare($sqlString);
      $st->bindValue(':id', $this->id, PDO::PARAM_INT);
      $st->execute();
      $conn = null;
    }
    else
    {
      //error: $this->id was not set.
    }
  }
  
}