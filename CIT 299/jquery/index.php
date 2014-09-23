


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">  

<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr">  

<head>  

    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />  

    <title>my jquery test page</title>  

    <link rel="stylesheet" href="style.css" type="text/css" media="screen" />  

    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.2/jquery.min.js"></script>

	<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.12/jquery-ui.min.js"></script>

    <script src="myjquery.js" type="text/javascript"></script>  

</head>  

<body>  

	<div class="hidden" id="Popup1">

		1alsjfklajsdflasjd; asdljf asdf jklasdjfalsdfj ;lasdj <br>

		1alksjdf aklsjfl as<br>

		1alsdjkf klasjdf asdkjf lasjdf kjasdfk jkasld j<br>

		1aklsdfjklasf

	</div>

	<div class="hidden" id="Popup2">

		2alsjfklajsdflasjd; asdljf asdf jklasdjfalsdfj ;lasdj <br>

		2alksjdf aklsjfl as<br>

		2alsdjkf klasjdf asdkjf lasjdf kjasdfk jkasld j<br>

		2aklsdfjklasf

	</div>

	<div class="hidden" id="Popup3">

		123 123 123 123 123 123

	</div>

	<div class="hidden" id="Popup4">

		4 4 4 4 4 4

	</div>

	<div class="hidden" id="Popup5">

		55555555555555555555555555

	</div>

	<div class="hidden" id="Popup6">

		six!<br>

		6 here

	</div>

	<div class="hidden" id="Popup7">

		7alsjfklajsdflasjd; asdljf asdf jklasdjfalsdfj ;lasdj <br>

		7alksjdf aklsjfl as<br>

		7alsdjkf klasjdf asdkjf lasjdf kjasdfk jkasld j<br>

		7aklsdfjklasf

	</div>

	<input type="button" value="Popup1"/>

	<input type="button" value="Popup2"/>

	<input type="button" value="Popup3"/>

	<input type="button" value="Popup4"/>

	<input type="button" value="Popup5"/>

	<input type="button" value="Popup6"/>

	<input type="button" value="Popup7"/>

	

	<div class="hidden" id="table_direction">

		Drag and drop the numbered boxes onto parts of the board.

	</div>

	<div class="hidden" id="input_direction">

		Enter color value: <br>

		Use 6 digit hexadecimal OR word color format (eg: red, yellow, blue)

	</div>

	<table><tbody>
	<?php
		for ($row = 1; $row <= 8; $row++)
		{
			echo "<tr>";
			for ($col = 1; $col <=8; $col++)
			{
				echo "
					<td id='$row$col'>
						<div class='box' id='$row$col'>$row$col</div>
					</td>
					";
			}
			echo "</tr>";
		}
	?>
	</tbody></table>
	<form>

		<input type="text" name="color"/>

		<input type="button" name="change color" value="Change board color"/>

	</form>

	<p>
		When you click on this paragraph, jQuery will change<br>
		the background of this paragraph to another color!
	</p>
</body>  

</html>  