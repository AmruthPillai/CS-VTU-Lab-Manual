<?php
//current time + 20 seconds
$inTwentySeconds = 20  + time();

//if cookies are present
if(isset($_COOKIE['lastVisit']))
{
	//get the value from the cookie
	$visit = $_COOKIE['lastVisit'];
  echo "Your last visit was - ". $visit;
}
//if cookie is expired
else
{
	//setcookie(name,value,expire)
  setcookie('lastVisit', date("h:i:s A - m/d/y"), $inTwentySeconds);
  echo "You've got some expired  cookies!";
}

?>
