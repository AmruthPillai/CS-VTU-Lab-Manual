## Aim
Develop and demonstrate using Javascript, a XHTML Document that collects the USN of the user.

The valid format of USN is:  
1) 1 digit from 1 to 4  
2) 2 upper-case characters  
3) 2 digits from 0 to 9  
4) 2 upper-case characters  
5) 3 digits from 0 to 9  

No spaces are allowed in between. Event handler must be included in the form element that collects this information to validate this input. Messages in the alert window must be displayed when errors are detected.

## Code
```
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Program 2 - Validate USN</title>

    <script type="text/javascript">
      function validateUSN() {
        var usnRegExp = /^[1-4][A-Z][A-Z][0-9][0-9][A-Z][A-Z][0-9][0-9][0-9]$/;
        var str = document.getElementById('usn').value;

        if (!str.match(usnRegExp) || str.length != 10) {
          alert("Invalid USN");
          return false;
        } else {
          alert("Valid USN");
          return true;
        }
      }
    </script>
  </head>
  <body>
    <form>
      <label>Enter an USN:</label>
      <input type="text" id="usn">
      <input type="submit" value="Validate USN" onclick="validateUSN()">
    </form>
  </body>
</html>
```

## Output
<img width="1042" alt="screen shot 2017-10-22 at 11 46 05 pm" src="https://user-images.githubusercontent.com/1134738/31864925-962f5e9e-b783-11e7-82bf-5f265e83ae25.png">

<img width="1043" alt="screen shot 2017-10-22 at 11 47 59 pm" src="https://user-images.githubusercontent.com/1134738/31864926-965ead34-b783-11e7-8f5c-d79e0d80236c.png">

<img width="1046" alt="screen shot 2017-10-22 at 11 48 22 pm" src="https://user-images.githubusercontent.com/1134738/31864927-968b3e12-b783-11e7-8aa9-22a92599bdfa.png">
