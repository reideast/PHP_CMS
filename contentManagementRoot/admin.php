<?php
session_start();

require_once('classPage.inc');
require_once('../contentManagementInclude/adminInfo.inc');

$action = (isset($_REQUEST['action']) && $_REQUEST['action']) ? $_REQUEST['action'] : '';
$user = (isset($_SESSION['user']) && $_SESSION['user']) ? $_SESSION['user'] : '';

$pageTitle = 'Administrate Honeymoon';
include('_headerHead.inc');
include('_headerTail.inc');
if ($action != 'login' && $action != 'logout' && !$user)
{
  login();
}
else
{
  switch ($action)
  {
    case 'login':
      login();
      break;
    case 'logout':
      logout();
      break;
    case 'newPage':
      newPage();
      break;
    case 'editPage':
      editPage();
      break;
    case 'deletePage':
      deletePage();
      break;
    default:
      listPages();
  }
}
include('_footer.inc');

//*************************************************************************************

function login()
{
  $results = array();
  
  if (isset($_POST['login']) && $_POST['login'])
  {
    //true login
    if ($_POST['user'] == ADMIN_USER && SHA1($_POST['pass']) == ADMIN_PW)
    {
      $_SESSION['user'] = ADMIN_USER;
      echo '<p>Login successful.</p>'; // <a href="admin.php">Click here to continue.</a></p>';
      listPages();
    }
    elseif ($_POST['user'] == ADMIN_USER2 && SHA1($_POST['pass']) == ADMIN_PW2)
    {
      $_SESSION['user'] = ADMIN_USER2;
      echo '<p>Login successful.</p>'; // <a href="admin.php">Click here to continue.</a></p>';
      listPages();
    }
    else //LOGIN WAS INCORRECT
    {
      $results['errorMessage'] = 'Incorrect user name or password.';
      include('_adminLoginForm.inc');
    }
  }
  else
  {
    include('_adminLoginForm.inc');
  }
}

function logout()
{
  unset($_SESSION['user']);
  echo '<p>You have been logged out.</p>';
  login();
}

function newPage()
{
  $results = array();
  
  $results['formAction'] = 'newPage';
  
  if (isset($_POST['saveChanges']) && $_POST['saveChanges'])
  {
    $page = new Page;
    $page->storeFormValues($_POST);
    $page->insert();
    echo '<p>Saved as new page.</p>';
    echo '<META HTTP-EQUIV="Refresh" Content="0; URL=admin.php?action=editPage&amp;pageID=' . $page->id . '">'; //open page after 0 seconds
  }
  elseif (isset($_POST['cancel']) && $_POST['cancel'])
  {
    echo '<p>New page canceled.</p>';
    listPages();
  }
  else
  {
    $results['page'] = new Page;
    include('_adminEditPage.inc');
  }
}

function editPage()
{
  //echo '<p>$_REQUEST["pageID"] = ' . (int) $_REQUEST['pageID'] . '</p>';

  $results = array();
  
  $results['formAction'] = 'editPage';
  
  if (isset($_REQUEST['saveChanges']) && $_REQUEST['saveChanges'])
  {
    if ($page = Page::getByID((int) $_REQUEST['pageID']))
    {
      $page->storeFormValues($_REQUEST);
      $page->update();
      echo '<META HTTP-EQUIV="Refresh" Content="0; URL=admin.php?action=editPage&amp;pageID=' . $page->id . '">'; //open page after 0 seconds
    }
    else
    {
      echo '<p>Page not found by ID Changes not saved!</p>';
    }
  }
  elseif (isset($_REQUEST['cancel']) && $_REQUEST['cancel'])
  {
    echo '<p>Edit canceled.</p>';
    listPages();
  }
  else
  {
    $results['page'] = Page::getByID((int) $_REQUEST['pageID']);
    include('_adminEditPage.inc');
  }
}

function deletePage()
{
  if ($page = Page::getByID((int) $_GET['pageID']))
  {
    $titleToDelete = $page->pageTitle;
    $page->delete();
    echo '<p>Page "' . $titleToDelete . '" deleted.</p>';
  }
}

function listPages()
{
  $results = array();
  $data = Page::getList();
  $results['pages'] = $data['results'];
  $results['totalRows'] = $data['totalRows'];
  
  include('_adminListPages.inc');
}
?>