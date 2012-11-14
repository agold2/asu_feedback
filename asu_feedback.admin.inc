<?php
// $Id: 

/**
 * @file
 * Module admin page callbacks.
 */


/**
 * Implements the settings page.
 *
 * @return
 *   The form structure.
 */
function asu_feedback_admin_settings() {
  global $base_url;
  $visibility_notlisted = 0;
  $visibility_listed = 1;

  $form['system_options'] = array(
    '#type' => 'fieldset',
  );
 
   $options = array(
     $visibility_notlisted => t('All pages except those listed'),
     $visibility_listed => t('Only the listed pages'),
   );
  //$php_access = user_access('use PHP for settings');
  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));
  /*
  if (module_exists('php') && $php_access) {
	  $options += array(FEEDBACK_VISIBILITY_PHP => t('Pages on which this PHP code returns <code>TRUE</code> (experts only)'));
  }
   */
  $form['system_options']['asu_feedback_visibility'] = array( 
    '#type' => 'radios',
    '#title' => t('Show ' . l('Leave Feedback', $base_url . '/feedback') . ' on specific pages.'),
    '#options' => $options,
    '#default_value' => variable_get('asu_feedback_visibility', $visibility_notlisted),
  );


  $feedback = variable_get('asu_feedback_paths', '');
  $form['system_options']['asu_feedback_paths'] = array(
    '#type' => 'textarea',
    '#default_value' => $feedback,
    '#cols' => 60,
    '#rows' => 5,
    '#description' => $description,
  );
		      
  $form['system_options_n'] = array(
    '#type' => 'fieldset',
  );
  $form['system_options_n']['visibility_access'] = array( 
    '#type' => 'radios',
    '#title' => t('Show ' . l('Request Access', $base_url . '/request-access') . ' on specific pages.'),
    '#options' => $options,
    '#default_value' => variable_get('asu_feedback_access_visibility', $visibility_notlisted),
  );
		            
			        

  $access = variable_get('asu_feedback_access', '');
  $form['system_options_n']['asu_feedback_access'] = array(
    '#type' => 'textarea',
    '#default_value' => $access,
    '#cols' => 60,
    '#rows' => 5,
    '#description' => $description,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

/**
 * Submit hook for the settings form.
 */
function asu_feedback_admin_settings_submit($form, &$form_state) {
  $op = $form_state['clicked_button']['#value'];
  $values = $form_state['values'];
  switch ($op) {
    case t('Save Configuration'):
      //$downtown_major_codes = array();
      //$downtown_major_codes = explode("\n", $values['asu_feedback_downtown_majorcodes']);
      $feedback = trim($values['asu_feedback_paths']);
      $access = trim($values['asu_feedback_access']);
      
      variable_set('asu_feedback_paths', $feedback);
      variable_set('asu_feedback_visibility', $values['asu_feedback_visibility']);
      variable_set('asu_feedback_access', $access);
      variable_set('asu_feedback_access_visibility', $values['visibility_access']);
      drupal_set_message(t('The configuration options have been saved.'));
      break;
    case t('Reset to defaults'):
      //variable_del('asu_feedback_downtown_majorcodes');

      drupal_set_message(t('The configuration options have been reset to their default values.'));
      break;
  }

  // Rebuild the menu router.
  menu_rebuild();
}

