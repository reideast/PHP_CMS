  
  <link rel="stylesheet" href="css/main.css" type="text/css" />

  <title><?php echo $pageTitle; ?></title>
</head>

<body id="htmlBody">

  <header id="pageMenuWrapper">
    <div id="pageMenu">
      <div id="pageMenuTitle">
        <h2>Honeymoon</h2>
        <h4>of Awesome</h4>
      </div>
      <div id="pageMenuLogo">
        <a href="index">
          <img src="resources/pageResources/icon_wedding.jpg" width="128" height="128" />
        </a>
      </div>
      <nav id="pageMenuNav">
        <ul>
<?php 
          if (isset($_SESSION['user']) && $_SESSION['user'])
            include('_navAdmin.inc');
          require_once('classPage.inc');
          $arrayPages = Page::getList();
          foreach ($arrayPages['results'] as $row)
          {
            echo '<li' . ($currPageURL == $row->pageURL ? ' class="currentPage"' : '') . '><a href="' . $row->pageURL . '">' . $row->navTitle . '<aside>' . $row->navSubtitle . '</aside></a></li>' . "\r\n";
          }
          //hack:
?>
        </ul>
      </nav>
    </div>
    <div id="pageMenuBottom"></div>
  </header>

  <section id="pageBody">
    <header id="pageBodyTitle">
      <h1><?php echo $pageTitle; ?></h1>
    </header>

    <section id="pageBodyContent">
      <article id="<?php echo $pageTitle; ?>">