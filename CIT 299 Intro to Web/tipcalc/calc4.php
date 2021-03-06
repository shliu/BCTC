<!doctype html>
<html>
	<head>
		<title>Javascript Tip Calculator</title>
		<script type="text/javascript" src="tipheaderbody4.js"></script>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body>
		<form class="myform">
			<table>
				<tbody>
					<tr>
						<td>Check total: </td>
						<td><input type="text" name="checktotal"></td>
					</tr>
					<tr>
						<td>Custom Tip %: </td>
						<td><input type="text" name="tippercent"></td>
					</tr>
					<tr>
						<td>Standard Tip?: </td>
						<td><input type="checkbox" name="wantsstdtip" onClick="toggle(this.form.tippercent);"></td>
					</tr>
					<tr>
						<td>12%</td>
						<td><input type="radio" name="stdtipvals" value=12 checked></td>
					</tr>
					<tr>
						<td>15%</td>
						<td><input type="radio" name="stdtipvals" value=15></td>
					</tr>
					<tr>
						<td>18%</td>
						<td><input type="radio" name="stdtipvals" value=18></td>
					</tr>
					<tr>
						<td>20%</td>
						<td><input type="radio" name="stdtipvals" value=20></td>
					</tr>
					<tr>
						<td>Bonus:</td>
						<td>
							<select name="bonusamount">
								<option value=0>$0</option>
								<option value=1>$1</option>
								<option value=2>$2</option>
								<option value=3 selected>$3</option>
								<option value=4>$4</option>
								<option value=5>$5</option>
							</select>
						</td>
					</tr>
					<tr>
						<td colspan="2"><input type="button" value="Calculate Tip" onClick="calcTip(this.form);"></td>
					</tr>
					<tr>
						<td>Tip mount: </td>
						<td><input type="text" name="tipamount"></td>
					</tr>
				</tbody>
			</table>
		</form>
	</body>
</html>