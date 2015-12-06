DROP TABLE IF EXISTS pages;
CREATE TABLE pages
(
  id              smallint unsigned NOT NULL auto_increment,
  
  
  pageURL         varchar(255) NOT NULL,                      #one-word name for http
  displayOrder    smallint NOT NULL,                          #numeric way to order pages in nav bar
  navTitle        varchar(255) NOT NULL,                      #displayed on the nav bar
  navSubtitle     varchar(255) NOT NULL,                      #nav subtitles
  
  pageTitle       varchar(255) NOT NULL,                      #displayed at the top of the page, also <title>
  pageContent     mediumtext NOT NULL,                        #The HTML content of the page

  PRIMARY KEY     (id)
);

INSERT INTO pages (`id`, `pageURL`, `displayOrder`, `navTitle`, `navSubtitle`, `pageTitle`, `pageContent`, `pageHeadCustomize`, `useJQuery`, `useFancyBox`, `useFancyBoxGallery`) VALUES (NULL, 'index', '0', 'Home', 'return to start', 'New Web Site', '<p>Hello, world!</p>', NULL, '0', '0', '0');