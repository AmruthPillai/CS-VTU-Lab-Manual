## Aim
Develop and demonstrate a XHTML file that includes Javascript for the following problem:  
`Input:` A number n obtained using prompt  
`Output:` The first n fibonacci series

## Code
```
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Program 01a - Fibonacci</title>

    <script type="text/javascript">
      function calcFibonacci() {
        var n = prompt("Enter the max limit of fibonacci series to generate:");
        n = parseInt(n);

        var y1 = 0, y2 = 1, res;

        if (n <= 0)
          document.write("Fibonacci Series is not possible.");

        if (n == 1)
          document.write(y1);

        if (n > 1)
          document.write(y1 + " " + y2);

        for (var i = 2; i < n; i++) {
          res = y1 + y2;
          y1 = y2;
          y2 = res;
          document.write(" " + res);
        }
      }
    </script>
  </head>
  <body onload="calcFibonacci()">

  </body>
</html>
```

## Output
<img width="1326" alt="screen shot 2017-10-22 at 10 33 39 pm" src="https://user-images.githubusercontent.com/1134738/31864338-3f154646-b779-11e7-93b1-3a0ff190fec7.png">

<img width="1325" alt="screen shot 2017-10-22 at 10 33 54 pm" src="https://user-images.githubusercontent.com/1134738/31864339-3f444220-b779-11e7-9fe3-5402414de34f.png">
