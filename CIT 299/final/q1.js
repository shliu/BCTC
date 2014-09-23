function do_q1(thisform) {
	var ticket_cost;
	var extra_cost;
	var total_price;
	
	if (thisform.ticket_type[0].checked) //matinee
		ticket_cost = thisform.ticket_type[0].value * 1;
	else if (thisform.ticket_type[1].checked) //evening
		ticket_cost = thisform.ticket_type[1].value * 1;
	else //weekend
		ticket_cost = thisform.ticket_type[2].value * 1;
		
	if (thisform.wants_3d.checked)
		extra_cost = 2;
	else //doesn't want 3D
		extra_cost = 0;
		
	total_price = ticket_cost + extra_cost;
	
	thisform.price.value = total_price;
	}