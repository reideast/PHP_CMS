Name:    PHP_CMS
Author:  Andrew Reid East

Background: This is a PHP program to manage a simple, flat web site. Logins and database access are hard coded in separate files and unencrypted, and overall page security has not been evaluated. The HTML/CSS template is not set up to be easily modified, but can be changed just by editing header/footer PHP files and the stylesheet.



## Files of Interest ##

* Retrieve pages from database:
 * getPage.php - pulls page by name from database to display, combining _header.inc, _footer.inc, and code from database
 * classPage.inc - my attempt at object-oriented PHP, this class retrieves, saves, and deletes pages from the database
 * .htaccess - uses mod_rewrite to translate "pageTitle" into "getPage.php?pageID=pageTitle" (unseen by website visitors)
* HTML/CSS Template:
 * _headerHead.inc, _headerTail.inc, _footer.inc - PHP pages to display HTML from template
 * css/main.css - CSS for template (uses an .htaccess rule to allow PHP variables in CSS; has smart caching to avoid stale files)
 * resources/pageResources/ - image files for template found here
*Content Management:
 * admin.php - a single page to list/edit/create pages in the CMS
 * _adminEditPage.inc, _adminListpages.inc, _adminLoginForm.inc - stub files separated from admin.php to display requested admin function

  
  
## How to Use ##

Place both folder on web server
Direct web domain to: contentManagementRoot/
Do not set contentManagementInclude/ as inaccessible to the Internet

Edit contentManagementInclude/adminInfo.inc to set up your logins
Edit contentManagementInclude/dbdata.inc to set up the connection to your MySQL database
Run contentManagementInclude/setupDatabase.sql in MySQL to set up tables

Open "admin.php" on your web domain: http://www.example.com/admin.php to login

Use the _footer.inc, _headerHead.inc, and _headerTail.inc files to edit the PHP/HTML template design