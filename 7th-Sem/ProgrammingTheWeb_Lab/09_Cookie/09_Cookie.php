<?php
  $inTwoMonths = 60 * 60 * 24 * 60 + time();

  setCookie('lastVisit', date("G:i -m/d/y"), $inTwoMonths);

  if (isset($_COOKIE['lastVisit'])) {
    $visit = $_COOKIE['lastVisit'];
    echo "Your last visit was on " . $visit;
  } else
    echo "You've got some expired cookies! <br>";
?>
