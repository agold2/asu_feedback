ASU Feedback
------------
* Displays Feedback button at bottom of page.
* Hovering over the Feedback button shows a
  cluetip with up to three links: 1) Help 2) Leave Feedback and 3) Request Access
* User will be logged in through CAS when clickoing on Leave Feedback or Request Access.
* Leave Feedback and Request access are webforms. When submitted the ASURITE and page where
  they clicked link is submitted through email.

Installation
-------------------------
1) Enable Drupal Modules: ASU Brand, CAS, Cluetip, Libraries, Link, Webform
2) Install Cluetip Library: https://github.com/kswedberg/jquery-cluetip
    * Upload LIbrary to sites/all/libraries and rename it cluetip
3) Enable this module

Usage
-----
1) Enable Module
2) Set display options at http://example.asu.edu/admin/config/asu_feedback
3) Add existing field "Link: asu_feedback_help (Help Link)" to each content
  type that you would like to add a Help Link.
4) Edit each webform to add components, change email address where form is sent, etc.

Troubleshooting
--------------
* If CAS breaks: the Libraries module requires that the CAS library is installed in /sites/all/libraries
* Note: Uninstalling will delete the Leave Feedback and Request Access webforms and the Help Link field.
* If you experience issues please report them at https://github.com/agold2/asu_feedback/issues

Created by Ariel Gold
ariel.gold at Arizona State University . edu
