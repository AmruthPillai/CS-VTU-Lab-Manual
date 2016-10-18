<?php
$inTwentySeconds = 20  + time();

if(isset($_COOKIE['lastVisit']))
{
	$visit = $_COOKIE['lastVisit'];
  echo "Your last visit was - ". $visit;
}

else
{
  setcookie('lastVisit', date("h:i:s A - m/d/y"), $inTwentySeconds);
  echo "You've got some expired  cookies!";
}

?>
