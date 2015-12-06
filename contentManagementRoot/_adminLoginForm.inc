<form action="admin.php?action=login" method="post">
  <input type="hidden" name="login" id="login" value="true" />
  
  <?php if (isset($results['errorMessage']) && $results['errorMessage']) echo '<div class="errorMessage">' . $results['errorMessage'] . '</div>'; ?>
  
  <p><label for="user">Username: </label><input type="text" name="user" id="user" required maxlength="20" <?php echo (isset($_POST['user']) && $_POST['user']) ? 'value="'.$_POST['user'].'"' : 'autofocus'; ?> /></p>
  
  <p><label for="pass">Password: </label><input type="password" name="pass" id="pass" required maxlength="20" <?php echo (isset($_POST['user']) && $_POST['user']) ? 'autofocus ' : ' '; ?>/></p>
  
  <p><input type="submit" name="submit" id="submit" value="Login" />
</form>