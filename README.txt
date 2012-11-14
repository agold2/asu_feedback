ASU Feedback
============

* Displays Feedback button at bottom of page.
* When hovering over the Feedback button up to
  three links will appear in a Cluetip.
    1) Help 
    2) Leave Feedback
    3) Request Access
* User will be logged in through CAS and ASURITE
and page where they clicked link is submitted through
email

Installation
-------------------------
* Enable Drupal Modules: ASU Brand, CAS, Cluetip, Libraries, Link, Webform
* Cluetip Library: https://github.com/kswedberg/jquery-cluetip
    - Upload LIbrary to sites/all/libraries and rename it cluetip
* Enable this module

Usage
-----

* Enable Module
* Set display options at http://example.asu.edu/admin/config/asu_feedback
* Provides "Link to Help Page." At http://example.asu.edu/admin/structure/types
  you can manage fields for each content type you want to be able to specify
  a link to a help page. Go to "Manage Display" and set format to "Hidden" to not show
  the link in the main content.


Notes
-----



Created by Ariel Gold 
ariel.gold at Arizona State University . edu
