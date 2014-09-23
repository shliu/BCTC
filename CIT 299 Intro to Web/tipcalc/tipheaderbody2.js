function calcTip(formdata) {
	var checktotal;
	var tippercent;
	var tipamount;
	var wantsstdtip;
	var actualtippercent;
	
	checktotal = formdata.checktotal.value;
	tippercent = formdata.tippercent.value;
	wantsstdtip = formdata.wantsstdtip.checked;
	
	if (wantsstdtip)
		actualtippercent = 15;
	else
		actualtippercent = tippercent;
		
	tipamount = checktotal * actualtippercent / 100;
	
	formdata.tipamount.value = tipamount;	
	}
	

	
	
function toggle(form_input) {
	if (form_input.disabled == true)
		form_input.disabled = false;
	else
		form_input.disabled = true;
	}
