<style>
  thead th {
    text-align:left;
  }
</style>
<table style="width:100%">
  <thead>
    <tr>
      <th></th>
      <th>navTitle</th>
      <th>pageURL</th>
      <th>pageTitle</th>
      <th>arrange</th>
      <th></th>
    </tr>
  </thead>
  <tbody>
<?php
  foreach ($results['pages'] as $page)
  {
?>
    <tr>
      <td><a href="admin.php?action=editPage&amp;pageID=<?php echo $page->id; ?>">edit</a></td>
      <td><?php echo $page->navTitle; ?></td>
      <td><?php echo $page->pageURL; ?></td>
      <td><?php echo $page->pageTitle; ?></td>
      <td><?php echo $page->displayOrder; ?></td>
      <td><a href="admin.php?action=deletePage&amp;pageID=<?php echo $page->id; ?>" onclick="return confirm('Are you sure you want to delete ' + <?php echo $page->navTitle; ?> + '?');">delete</a></td>
    </tr>
<?php
  }
?>
  </tbody>
</table>
<hr />
<p><a href="admin.php?action=newPage">Insert New Page</a></p>