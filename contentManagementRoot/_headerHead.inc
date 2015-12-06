<?php date_default_timezone_set( "America/Los_Angeles" ); ?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta http-equiv="content-type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" href="css/normalize.css" type="text/css" />
  
  <link href='http://fonts.googleapis.com/css?family=Oxygen:400,700|Quattrocento:700|Lovers+Quarrel|Amatic+SC' rel='stylesheet' type='text/css'>
  
  <link rel="icon" type="image/png" href="resources/pageResources/iconWedding.png" />
  <link rel="shortcut icon" href="resources/pageResources/iconWedding.ico" />
  
<?php if ($page->useJQuery == 1) { ?>
  <script type="text/javascript" src="lib/jquery/jquery-1.10.2.min.js"></script>
<?php } ?>
<?php if ($page->useFancyBox == 1) { ?>
  <script type="text/javascript" src="lib/fancybox/jquery.fancybox.js?v=2.1.5"></script>
  <link rel="stylesheet" type="text/css" href="lib/fancybox/jquery.fancybox.css?v=2.1.5" media="screen" />
  <script type="text/javascript">
    $(document).ready(function() {
      $(".fancybox").fancybox();
    });
</script>
<?php } ?>
<?php if ($page->useFancyBoxGallery == 1) { ?>
  <script type="text/javascript" src="lib/jquery/jquery.mousewheel-3.0.6.pack.js"></script>
  <link rel="stylesheet" type="text/css" href="lib/fancybox/helpers/jquery.fancybox-thumbs.css?v=1.0.7" />
  <script type="text/javascript" src="lib/fancybox/helpers/jquery.fancybox-thumbs.js?v=1.0.7"></script>
  <script type="text/javascript" src="lib/fancybox/helpers/jquery.fancybox-media.js?v=1.0.6"></script>
  <link rel="stylesheet" href="lib/fancybox/helpers/jquery.fancybox-buttons.css?v=1.0.5" type="text/css" media="screen" />
  <script type="text/javascript" src="lib/fancybox/helpers/jquery.fancybox-buttons.js?v=1.0.5"></script>
<?php } ?>
