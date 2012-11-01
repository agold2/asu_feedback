<?php

/**
 * @file
 * Admin page callbacks for the filter module.
 */

/**
 * Menu callback; Displays a list of all text formats and allows them to be rearranged.
 *
 * @ingroup forms
 */
function asu_feedback_admin_overview($form) {
  $header = array(t('Type'), t('Webform Path'), t('Operations'));
  $result = db_query('SELECT fid,name,webform_path, weight FROM {asu_feedback}');

  $rows = array();
  $destination = drupal_get_destination();
  foreach ($result as $data) {
    $row = array();
    $row['data']['name'] = $data->name;
    $row['data']['webform_path'] = $data->webform_path;

    $operations = array();
    $operations['edit'] = array(
      'title' => t('edit'),
      'href' => "admin/config/asu_feedback/edit/$data->fid",
      'query' => $destination,
    );
    $operations['delete'] = array(
      'title' => t('delete'),
      'href' => "admin/config/asu_feedback/delete/$data->fid",
      'query' => $destination,
    );
    $row['data']['operations'] = array(
      'data' => array(
        '#theme' => 'links',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline', 'nowrap')),
      ),
    );

    $row['data']['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight for @title', array('@title' => $data->name)),
      //'#title_display' => 'invisible',
      '#default_value' => $data->weight,
    );

    $rows[] = $row;
  }
  
  $form['asu_feedback_form'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No Feedback buttons defined. <a href="@link">Add Feedback Type</a>.', array('@link' => url('admin/config/asu_feedback/add'))),
  );

  return $form;
}


/**
 * Page callback: Returns a form creating or editing a Feedback type.
 *
 * @param $path
 *   An array containing the path ID, source, alias, and language code.
 *
 * @return
 *   A form for adding or editing a Feedback type.
 *
 * @see path_menu()
 */
function asu_feedback_admin_edit($type = array()) {
  if ($type) {
    drupal_set_title($type['name']);
    $output = drupal_get_form('asu_feedback_admin_form', $type);
  }
  else {
    $output = drupal_get_form('asu_feedback_admin_form');
  }

  return $output;
}


/**
 * Form constructor for the path administration form.
 *
 * @param $path
 *   An array containing the path ID, source, alias, and language code.
 *
 * @ingroup forms
 * @see path_admin_form_validate()
 * @see path_admin_form_submit()
 * @see path_admin_form_delete_submit()
 */
function asu_feedback_admin_form($form, &$form_state, $type = array('name' => '', 'webform_path' => '', 'fid' => NULL)) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Feedback type'),
    '#default_value' => $type['name'],
    '#maxlength' => 255,
    '#size' => 45,
    '#description' => t('Specify the existing path you wish to alias. For example: node/28, forum/1, taxonomy/term/1.'),
   //'#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['webform_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Webform path'),
    '#default_value' => $type['webform_path'],
    '#maxlength' => 255,
    '#size' => 45,
    '#description' => t('Specify an alternative path by which this data can be accessed. For example, type "about" when writing an about page. Use a relative path and don\'t add a trailing slash or the URL alias won\'t work.'),
    //'#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
/*
  // This will be a hidden value unless locale module is enabled.
  $form['language'] = array(
    '#type' => 'value',
    '#value' => $path['language']
  );
*/
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['delete'] = array(
     '#type' => 'submit',
     '#value' => t('Delete'),
     '#submit' => array('asu_feedback_admin_form_delete_submit'),
   );
/*
  if ($path['pid']) {
    $form['pid'] = array(
      '#type' => 'hidden',
      '#value' => $path['pid'],
    );
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('path_admin_form_delete_submit'),
    );
  }
*/
  return $form;
}



/**
 * Form submission handler for path_admin_form().
 *
 * @see path_admin_form_validate()
 * @see path_admin_form_delete_submit()
 */
function asu_feedback_admin_form_submit($form, &$form_state) {
  // Remove unnecessary values.
  form_state_values_clean($form_state);
  
  drupal_write_record('asu_feedback', $form_state['values']);
  drupal_set_message(t('The Feedback Type has been saved.'));
  $form_state['redirect'] = 'admin/config/asu_feedback';
}



/**
 * Form submission handler for the 'Delete' button on path_admin_form().
 *
 * @see path_admin_form_validate()
 * @see path_admin_form_submit()
 */
function asu_feedback_admin_form_delete_submit($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $form_state['redirect'] = array('admin/config/asu_feedback/delete/' . $form_state['values']['fid'], array('query' => $destination));
}

/**
 * Form constructor for the path deletion form.
 *
 * @param $path
 *   The path alias that will be deleted.
 *
 * @see path_admin_delete_confirm_submit()
 */
function asu_feedback_admin_delete_confirm($form, &$form_state, $type) {
  if (user_access('administer feedback types')) {
 
    dsm($form_state);
    $form_state['name'] = $type;
    return confirm_form(
      $form,
      t('Are you sure you want to delete feedback type %title?',
      array('%title' => $type['name'])),
      'admin/config/asu_feedback'
    );
  }
  return array();
}

/**
 * Form submission handler for path_admin_delete_confirm().
 */
function asufeedback_admin_delete_confirm_submit($form, &$form_state) {
  //if ($form_state['values']['confirm']) {
    //path_delete($form_state['type']['fid']);
    dsm('delete:' . $form_state);
    db_query("DELETE from {asu_feedback} where fid=%d", $form_state['name']['fid']);
    $form_state['redirect'] = 'admin/config/asu_feedback';
  ///}
}

