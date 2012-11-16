# ASU Feedback #

## About ##
Displays Feedback button at bottom of page. When hovering over the Feedback button a
cluetip appears with up to three links: 1) Help 2) Leave Feedback and 3) Request Access.
When clicking Leave Feedback or Request Access, the user is prompted to login via CAS,
if not already logged in. Leave Feedback and Request Access are webforms, and when
submitted the ASURITE and referring page are submitted along with any message to the
site email address.

## Installation ##
1. Install CAS library is installed in /sites/all/libraries
   If it is insalled in /sites/all/modules/contrib/cas/CAS e.g. move the CAS
   directory to /sites/all/libraries/CAS
2. Enable Drupal Modules: ASU Brand, CAS, Cluetip, Libraries, Link, Webform
3. Install Cluetip Library: https://github.com/kswedberg/jquery-cluetip
   * Upload LIbrary to sites/all/libraries and rename it cluetip
4. Enable this module

## Usage ##
1. Set display options at http://example.asu.edu/admin/config/asu_feedback
2. Add existing field "Link: asu_feedback_help (Help Link)" to each content
  type that you would like to add a Help Link.
3. Edit each webform to add components, change email address where form is sent, etc.


## Troubleshooting ##
* If CAS breaks: The Libraries module requires that the CAS library is installed in /sites/all/libraries





###### Created by Ariel Gold - ariel.gold at Arizona State University . edu
