function calcTip(formdata) {
	var checktotal;
	var tippercent;
	var tipamount;
	
	checktotal = formdata.checktotal.value;
	tippercent = formdata.tippercent.value;
	tipamount = checktotal * tippercent / 100;
	
	formdata.tipamount.value = tipamount;	
	}