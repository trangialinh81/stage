
			ind = 0;
			
				function point_it2(event){
					// recuperer les positions pointus par la souris
					pos_x = event.offsetX?(event.offsetX):event.pageX-document.getElementById("pointer_div2").offsetLeft;
					pos_y = event.offsetY?(event.offsetY):event.pageY-document.getElementById("pointer_div2").offsetTop;
					
					
				if (ind == 0)
					{
						ind = 1;
						document.pointform2.form5_x.value = pos_x;
						document.pointform2.form5_y.value = pos_y;
						document.getElementById("photo1").style.left = (pos_x - 5) ;
						document.getElementById("photo1").style.top = (pos_y-10) ;
						document.getElementById("photo1").style.visibility = "visible" ;
					}
					else if (ind == 1)
					{
						ind = 2;
						document.pointform2.form6_x.value = pos_x;
						document.pointform2.form6_y.value = pos_y;
						document.getElementById("photo12").style.left = (pos_x - 21) ;
						document.getElementById("photo12").style.top = (pos_y - 13) ;
						document.getElementById("photo12").style.visibility = "visible" ;
					}
					else if (ind == 2)
					{
						ind = 3;
						document.pointform2.form7_x.value = pos_x;
						document.pointform2.form7_y.value = pos_y;
						document.getElementById("photo13").style.left = (pos_x-37) ;
						document.getElementById("photo13").style.top = (pos_y-13) ;
						document.getElementById("photo13").style.visibility = "visible" ;

					}
					else if (ind == 3)
					{
						ind = 4;
						document.pointform2.form8_x.value = pos_x;
						document.pointform2.form8_y.value = pos_y;
						
						document.getElementById("photo14").style.left = (pos_x - 55) ;
						document.getElementById("photo14").style.top = (pos_y - 13) ;
						document.getElementById("photo14").style.visibility = "visible" ;
					}
				
				}
				 		
				function relance2(){
					indice =0;
					document.pointform2.form1_x.value = "";
					document.pointform2.form1_y.value = "";
					document.pointform2.form2_x.value = "";
					document.pointform2.form2_y.value = "";
					document.pointform2.form3_x.value = "";
					document.pointform2.form3_y.value = "";
					document.pointform2.form4_x.value = "";
					document.pointform2.form4_y.value = "";
					document.getElementById("photo").style.visibility = "hidden" ;
					document.getElementById("photo2").style.visibility = "hidden" ;
					document.getElementById("photo3").style.visibility = "hidden" ;
					document.getElementById("photo4").style.visibility = "hidden" ;
				}

