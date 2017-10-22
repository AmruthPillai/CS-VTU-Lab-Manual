## Aim
Develop and demonstrate a XHTML file that includes Javascript for the following problem:  
`Input:` A number n obtained using prompt  
`Output:` A table of numbers from 1 to n and their squares using alert

## Code
```
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Program 01b - Squares</title>

    <script type="text/javascript">
      function calcSquares() {
        var n = prompt("Enter a number:");

        if (num > 0 && num != null) {
          msg = "Number and it's Squares:\n";

          for (var i = 1; i <= n; i++)
            msg += i + " -- " + (i * i) + "\n";

          alert(msg);
        } else {
          alert("Please enter proper input!");
        }
      }
    </script>
  </head>
  <body onload="calcSquares()">

  </body>
</html>
```

## Output
<img width="1327" alt="screen shot 2017-10-22 at 11 21 57 pm" src="https://user-images.githubusercontent.com/1134738/31864726-3f2cb860-b780-11e7-87be-c1c362373a8b.png">

<img width="1502" alt="screen shot 2017-10-22 at 11 23 09 pm" src="https://user-images.githubusercontent.com/1134738/31864727-3f5b805a-b780-11e7-818d-a03d678068e6.png">
