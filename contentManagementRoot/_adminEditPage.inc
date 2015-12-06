<form id="adminPageEdit" action="admin.php?action=<?php echo $results['formAction']; ?>" method="post">
  <input type="hidden" name="pageID" value="<?php echo $results['page']->id; ?>" />

  <table>
    <tr>
      <td>
        <label for="navTitle">Nav Title</label>
      </td>
      <td>
        <input type="text" name="navTitle" id="navTitle" placeholder="To display in nav pane" required autofocus maxlength="50" value="<?php echo htmlspecialchars($results['page']->navTitle); ?>" />
      </td>
    </tr>
    <tr>
      <td>
        <label for="navSubtitle">Nav Subtitle</label>
      </td>
      <td>
        <input type="text" name="navSubtitle" id="navSubtitle" placeholder="Small text under Nav Title" required maxlength="75" value="<?php echo htmlspecialchars($results['page']->navSubtitle); ?>" />
      </td>
    </tr>
    
    <tr>
      <td>
        <label for="displayOrder">Display Order</label>
      </td>
      <td>
        <input type="text" name="displayOrder" id="displayOrder" placeholder="Numeric value order page in nav pane (small to large)" required maxlength="10" value="<?php echo htmlspecialchars($results['page']->displayOrder); ?>" />
      </td>
    </tr>

    <tr>
      <td>
        <label for="pageURL">URL</label>
      </td>
      <td>
        <input type="text" name="pageURL" id="pageURL" placeholder="Single-word URL" required maxlength="75" value="<?php echo htmlspecialchars($results['page']->pageURL); ?>" />
      </td>
    </tr>
    
    <tr>
      <td>
        <label for="pageTitle">Page Title</label>
      </td>
      <td>
        <input type="text" name="pageTitle" id="pageTitle" placeholder="H1 text at the top of the page text" required maxlength="75" value="<?php echo htmlspecialchars($results['page']->pageTitle); ?>" />
      </td>
    </tr>
    
    <tr>
      <td>
        <input type="checkbox" <?php echo (($results['page']->useJQuery == 1) ? 'checked' : '') ?> name="useJQuery" id="useJQuery" />
        <label for="useJQuery">Use jQuery?</label>
        <br />
        <p></p>
      </td>
      <td>
        <input type="checkbox" <?php echo (($results['page']->useFancyBox == 1) ? 'checked' : '') ?> name="useFancyBox" id="useFancyBox" />
        <label for="useFancyBox">Use fancybox for photos?</label>
        <br />
        <input type="checkbox" <?php echo (($results['page']->useFancyBoxGallery == 1) ? 'checked' : '') ?> name="useFancyBoxGallery" id="useFancyBoxGallery" />
        <label for="useFancyBoxGallery">Use fancybox gallery extension?</label>
      </td>
    </tr>
    
    <tr>
      <td colspan="2">
        <label for="pageHeadCustomize">Header Addendum</label>
        <textarea name="pageHeadCustomize" id="pageHeadCustomize" placeholder="Header HTML (optional)" cols="70" rows="3" maxlength="100000"><?php echo $results['page']->pageHeadCustomize; ?></textarea>
      </td>
    </tr>
    
    <tr>
      <td colspan="2">
        <label for="pageContent">Page Content</label>
        <textarea name="pageContent" id="pageContent" placeholder="Page HTML" cols="70" rows="10" required maxlength="100000"><?php echo $results['page']->pageContent; ?></textarea>
      </td>
    </tr>
    
    <tr>
      <td colspan="2">
        <input type="submit" name="saveChanges" value="Save Changes" />
        <input type="submit" formnovalidate name="cancel" value="Cancel" />
      </td>
    </tr>
  </table>
</form>