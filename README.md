# ASU Feedback #

## About ##
Displays Feedback button at bottom of page. When hovering over the Feedback button a
cluetip appears with up to three links: 1) Help 2) Leave Feedback and 3) Request Access.
Clicking Leave Feedback or Request Access, prompts user to login via CAS,
if not already logged in. Leave Feedback and Request Access are webforms, and when
submitted the ASURITE and referring page are submitted along with any message to the
site email address.

## Installation ##
1. Install CAS library in /sites/all/libraries
   If, e.g., it is installed in /sites/all/modules/contrib/cas/CAS e.g. move it
   to /sites/all/libraries
2. Install Cluetip Library: https://github.com/kswedberg/jquery-cluetip
   in sites/all/libraries and rename it so it is sites/all/libraries/cluetip
3. Enable Drupal Modules: ASU Brand, CAS, Cluetip, Libraries, Link, Webform
4. Enable this module

## Usage ##
1. Set display options at http://example.asu.edu/admin/config/asu_feedback
2. Add existing field "Link: asu_feedback_help (Help Link)" to each content
  type that you would like to add a Help Link.
3. If desired, edit each webform to add components, change email address where
  form is sent, etc.


## Troubleshooting ##
* If CAS breaks: The Libraries module requires that the CAS library is installed in /sites/all/libraries


###### Created by Ariel Gold - ariel.gold at Arizona State University . edu
