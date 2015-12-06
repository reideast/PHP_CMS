<?php
session_start();

require_once('classPage.inc');

if (isset($_REQUEST['pageID']) && $_REQUEST['pageID'])
{
  $currPageURL = $_REQUEST['pageID'];
  if ($page = Page::getByURL($currPageURL))
  {
    $pageTitle = $page->pageTitle;
    $pageHeadText = $page->pageHeadCustomize;
    $pageText = $page->pageContent;
  }
  else
  {
    $currPageURL = 'pageURL_not_found';
    $pageTitle = 'Error - Page Not Found';
    $pageText = '<p>The requested page was not found.</p>';
  }
}
else
{
  $currPageURL = 'pageID_not_set';
}

include('_headerHead.inc');
echo $pageHeadText;
include('_headerTail.inc');
echo $pageText;
include('_footer.inc');
?>