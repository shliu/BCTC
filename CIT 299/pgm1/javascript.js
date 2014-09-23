function myFunction(formdata) {
	var distance;
	var fuel_volume;
	var fuel_efficiency;
	var wants_diesel;
	var fuel_cost;
	var missing_data;
	
	distance = formdata.distance.value;
	fuel_volume = formdata.fuel_volume.value;
	fuel_efficiency = formdata.fuel_efficiency.value;
	wants_diesel = formdata.wants_diesel.checked;
	missing_data = formdata.missing_data[formdata.missing_data.selectedIndex].value;
	
	//get the cost of fuel, depending on selecte fuel type
	var cost_gasoline = 3.80;	//English gallon
	var cost_diesel = 4.05;		//English gallon
	if (wants_diesel)
		fuel_cost = cost_diesel;
	else
		fuel_cost = cost_gasoline;
	
	//calculate missing data
	if (missing_data == "distance")
		formdata.distance.value = fuel_efficiency * fuel_volume;
	else if (missing_data == "fuel_volume")
		formdata.fuel_volume.value = fuel_volume = distance / fuel_efficiency;
	else
		formdata.fuel_efficiency.value = distance / fuel_volume;
		
	//calculate cost of fuel depending on unit type
	if (formdata.unit[0].checked)
		;	//do nothing because original units are already English
	else if (formdata.unit[1].checked)
		fuel_volume /= 3.7854;
	else
		fuel_volume /= 0.8327;
	
	//calculate final cost of fuel
	formdata.final_cost.value = fuel_cost * fuel_volume;
	}
	

	

