<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">

    <html>
      <body>
        <h1>VTU Student's Information</h1>

        <table border="1">
          <tr>
            <th>Name</th>
            <th>USN</th>
            <th>College</th>
            <th>Branch</th>
            <th>Year</th>
            <th>Email</th>
          </tr>

          <xsl:for-each select="vtu/student">
            <xsl:choose>
              <xsl:when test="name='Raja Rajan A'">
                <tr bgcolor="blue">
                  <td><xsl:value-of select="name" /></td>
                  <td><xsl:value-of select="usn" /></td>
                  <td><xsl:value-of select="college" /></td>
                  <td><xsl:value-of select="branch" /></td>
                  <td><xsl:value-of select="year" /></td>
                  <td><xsl:value-of select="email" /></td>
                </tr>
              </xsl:when>

              <xsl:otherwise>
                <tr>
                  <td><xsl:value-of select="name" /></td>
                  <td><xsl:value-of select="usn" /></td>
                  <td><xsl:value-of select="college" /></td>
                  <td><xsl:value-of select="branch" /></td>
                  <td><xsl:value-of select="year" /></td>
                  <td><xsl:value-of select="email" /></td>
                </tr>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:for-each>
        </table>
      </body>
    </html>

  </xsl:template>
</xsl:stylesheet>
