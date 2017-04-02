
			indice = 0;
			an = 0;
			
				function point_it(event){
					// recuperer les positions pointus par la souris
					pos_x = event.offsetX?(event.offsetX):event.pageX-document.getElementById("pointer_div").offsetLeft;
					pos_y = event.offsetY?(event.offsetY):event.pageY-document.getElementById("pointer_div").offsetTop;
					
				if (indice == 0 || an == 1)
					{
						if (indice == 0)
							indice = 1;
						else
							an = 0;		
						document.pointform.form1_x.value = pos_x;
						document.pointform.form1_y.value = pos_y;
						document.getElementById("photo").style.left = (pos_x - 5) ;
						document.getElementById("photo").style.top = (pos_y-10) ;
						document.getElementById("photo").style.visibility = "visible" ;
					}
					else if (indice == 1 || an == 2)
					{
						if (indice == 1)
							indice = 2;
						else
							an = 0;
							
						document.pointform.form2_x.value = pos_x;
						document.pointform.form2_y.value = pos_y;
						document.getElementById("photo2").style.left = (pos_x - 21) ;
						document.getElementById("photo2").style.top = (pos_y - 13) ;
						document.getElementById("photo2").style.visibility = "visible" ;
					}
					else if (indice == 2 || an == 3)
					{
						if (indice == 2)
							indice = 3;
						else
							an = 0;
						document.pointform.form3_x.value = pos_x;
						document.pointform.form3_y.value = pos_y;
						document.getElementById("photo3").style.left = (pos_x-37) ;
						document.getElementById("photo3").style.top = (pos_y-13) ;
						document.getElementById("photo3").style.visibility = "visible" ;

					}
					else if (indice == 3 || an == 4)
					{
						if (indice == 3)
							indice = 4;
						else
							an = 0;

						document.pointform.form4_x.value = pos_x;
						document.pointform.form4_y.value = pos_y;
						
						document.getElementById("photo4").style.left = (pos_x - 55) ;
						document.getElementById("photo4").style.top = (pos_y - 13) ;
						document.getElementById("photo4").style.visibility = "visible" ;
					}
				
				}
				 		
				function relance(){
					indice =0;
					document.pointform.form1_x.value = "";
					document.pointform.form1_y.value = "";
					document.pointform.form2_x.value = "";
					document.pointform.form2_y.value = "";
					document.pointform.form3_x.value = "";
					document.pointform.form3_y.value = "";
					document.pointform.form4_x.value = "";
					document.pointform.form4_y.value = "";
					document.getElementById("photo").style.visibility = "hidden" ;
					document.getElementById("photo2").style.visibility = "hidden" ;
					document.getElementById("photo3").style.visibility = "hidden" ;
					document.getElementById("photo4").style.visibility = "hidden" ;
				}
				function annuler(text){
				
					if (an == 0)
					{
					
						if(text == '1' && indice > 0){
							document.pointform.form1_x.value = "";
							document.pointform.form1_y.value = "";
							document.getElementById("photo").style.visibility = "hidden" ;
							an = 1;
						}
						
						if(text == '2' && indice > 1){
							document.pointform.form2_x.value = "";
							document.pointform.form2_y.value = "";
							document.getElementById("photo2").style.visibility = "hidden" ;
							an = 2;
						}
						
						if(text == '3' && indice > 2){
							document.pointform.form3_x.value = "";
							document.pointform.form3_y.value = "";
							document.getElementById("photo3").style.visibility = "hidden" ;
							an = 3;
						}
						
						if(text == '4' && indice > 3){
							document.pointform.form4_x.value = "";
							document.pointform.form4_y.value = "";
							document.getElementById("photo4").style.visibility = "hidden" ;
							an = 4;
						}	
					}
					else
					{
						if(an == 1)
							window.alert ("Impossible d'annuler 2 fois. Choississez le 1er point ?");
						else
							window.alert ("Impossible d'annuler 2 fois. Choississez le " + an + "eme point ?");
					}					
				}
					function change(num) {
					document.getElementById("pointer_div").style.backgroundImage = "url('" + num + "')";
					relance ();
				}
