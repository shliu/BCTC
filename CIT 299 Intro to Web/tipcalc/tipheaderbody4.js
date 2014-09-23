function calcTip(formdata) {
	var checktotal;
	var tippercent;
	var tipamount;
	var wantsstdtip;
	var actualtippercent;
	var bonus;
	var subscript;
	
	checktotal = formdata.checktotal.value;
	tippercent = formdata.tippercent.value;
	wantsstdtip = formdata.wantsstdtip.checked;
	
	if (wantsstdtip)
		if (formdata.stdtipvals[0].checked) 
			actualtippercent = formdata.stdtipvals[0].value;
		else if (formdata.stdtipvals[1].checked) 
			actualtippercent = formdata.stdtipvals[1].value;
		else if (formdata.stdtipvals[2].checked) 
			actualtippercent = formdata.stdtipvals[2].value;
		else
			actualtippercent = formdata.stdtipvals[3].value;
	else
		actualtippercent = tippercent;
	
	subscript = formdata.bonusamount.selectedIndex;
	bonus = formdata.bonusamount.options[subscript].value;
	
	tipamount = (checktotal * actualtippercent / 100) + (bonus * 1);
	
	formdata.tipamount.value = tipamount;
	}
	

	


function toggle(form_input) {
	if (form_input.disabled == true)
		form_input.disabled = false;
	else
		form_input.disabled = true;
	}
