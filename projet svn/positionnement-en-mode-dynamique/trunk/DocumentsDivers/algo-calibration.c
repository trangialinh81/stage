#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef struct s_point
{
	double x;
	double y;
}point;

int factorielle(int n)
{
	int fact=1;
	int i;

	for (i=1; i<=n; i++)
		fact*=i;

	return fact;
}

// Donne le nombre de segments possible entre n points.
int nb_segments(int n)
{
    int nb=0;
	int i;

	for (i = 1; i <= (n - 1); i++)
		nb += i;

	return nb;
}

// Au moins 4 valeurs pour coefs.
/*
 * Calcul des position sur le repere camera en fonction des pointd de l'image.
 *
 * coords : points en entree
 * nbPoints: 
 * coefs : coeficients de changement de repere
 * nouvCoords : points en sortie.
 */
void calcul_coord_plan(point coords[], int nbPoints, double coefs[], point nouvCoords[])
{
	int i = 0;	

	for (i = 0 ; i < nbPoints ; i++)
	{
		nouvCoords[i].x = (coefs[1]/coefs[0]) * ((coords[i].x - coefs[2]) / (coords[i].y - coefs[3]));
		nouvCoords[i].y =  coefs[1] * (1 / (coords[i].y - coefs[3]));
		
	}
}

/*
 * Calcul des distance entre chaque points.
 * 
 * coords : points en entree
 * nbPoints: 
 * distances : distances en sortie
 * nbDists : nb de segments.
 */
double calcul_distances(point coords[], int nbPoints, double distances[], int nbDists)
{
	int i = 0, j = 0;
	int cpt = 0;
	double somme = 0.0;
	
	for (i = 0 ; i < (nbPoints - 1) ; i++)
	{
		for (j = (i + 1) ; j < nbPoints ; j++)
		{
			distances[cpt] = sqrt( pow(coords[i].x - coords[j].x, 2) + pow(coords[i].y - coords[j].y, 2));
			somme += distances[cpt];
			cpt ++;
		}
	}
	return somme;
}

/*
 * Calcul la somme des erreurs.
 *
 * dists : distances sur le plan
 * nouvDists : distances a comparer
 * nbSegments : 
 * 
 * return : somme des erreurs
 */
double somme_erreurs(double dists[], double nouvDists[], int nbSegments)
{
	int i = 0;
	double somme = 0.0;
	for (i = 0 ; i < nbSegments ; i++)
	{
		somme += fabs(dists[i] - nouvDists[i]);
	}
	
	return somme;
}

/*
 * Calcul des pentes entre chaque points.
 * 
 * coords : points en entree
 * nbPoints: 
 * pentes : pentes en sortie
 * nbPentes : 
 */
void calcul_pentes(point coords[], int nbPoints, double pentes[], int nbPentes)
{
	int i = 0, j = 0;
	int cpt = 0;
	double somme = 0.0;
	
	
	for (i = 0 ; i < (nbPoints - 1) ; i++)
	{
		for (j = (i + 1) ; j < nbPoints ; j++)
		{
			pentes[cpt] = (coords[i].y - coords[j].y) / (coords[i].x - coords[j].x);			
			cpt ++;
		}
	}
	
	return ;
}		

/*
 * Calcul les angles en fonction des pentes.
 * 
 * pentes : pentes en sortie
 * nbPentes :
 * angles : angles en entree 
 */
void calcul_angles(double pentes[], int nbPentes, double angles[])
{
	int i = 0;
	
	for (i = 0 ; i < nbPentes ; i++)
	{
		angles[i] = atan2(10 * pentes[i], 10);
	}
	
	return ;
}
 
int main() 
{
    
    const int NB_POINTS = 4;
	const int NB_SEGMENTS = nb_segments(NB_POINTS);
	
	point cPlan[NB_POINTS];
	point cImage[NB_POINTS];
    
    /***********************************
     *
     *  DONNEES EN ENTREE -> 8 points
     *
     ***********************************/
    // Coordonnees des point sur le plan (en metres).
	cPlan[0].x = 26.96;
	cPlan[0].y = 10.76;
	cPlan[1].x = 25.50;
	cPlan[1].y = 10.15;
	cPlan[2].x = 25.51;
	cPlan[2].y = 16.18;	
	cPlan[3].x = 25.51;
	cPlan[3].y = 13.39;
	
	// Coordonnees des points sur l'image (en pixels).
	// Orinige en haut a gauche.
	cImage[0].x = 41;
	cImage[0].y = 329;
	cImage[1].x = 85;
	cImage[1].y = 280;
	cImage[2].x = 497;
	cImage[2].y = 345;
	cImage[3].x = 283;
	cImage[3].y = 317;

	
	
	
	
	int i = 0;
	double betaU = 0.0, betaV = 0.0, u0 = 0.0, yh = 0.0; 
	// min-Max.
	double betaUm = 0.0, betaUM = 0.0;
	double betaVm = 0.0, betaVM = 0.0;	
	double u0m = 0.0, u0M = 0.0;	
	double yhm = 0.0, yhM = 0.0;
	
	
	double solution[5];
	double distance = 0, distancePlan = 0;	
	double distancesPlan[NB_SEGMENTS];
	double distances[NB_SEGMENTS];	
	double erreur = 0.0;
	
	point camera;
	point nouvCoords[NB_POINTS];
	double pentesPlan[NB_SEGMENTS];
	double anglesPlan[NB_SEGMENTS];
	
	double pentesImage[NB_SEGMENTS];	
	double anglesImage[NB_SEGMENTS];
	
	double moyAngles = 0.0;
	double angle = 0.0;
	double coefs[4];
	
	// Pour verification.
	double testX = 0.0;
	double testY = 0.0;
	double testDistance = 0.0;	
		
	solution[0] = 0.0;
	solution[1] = 0.0;
	solution[2] = 0.0;
	solution[3] = 0.0;
	solution[4] = 1100000.0;
	
	
	// Calculs des distances et angles pour les points du plan.
	distancePlan = calcul_distances(cPlan, NB_POINTS, distancesPlan, NB_SEGMENTS);
	for (i = 0 ; i < NB_SEGMENTS ; i ++)
	{
		printf("%f\n", distancesPlan[i]);
	}
	calcul_pentes(cPlan, NB_POINTS, pentesPlan, NB_SEGMENTS);
	calcul_angles(pentesPlan, NB_SEGMENTS, anglesPlan);
	
	
	// Boucle pour trouver les meilleurs coeficients.
	for (betaU = 100 ; betaU < 1500 ; betaU += 10)
	{	
		for (betaV = 100 ; betaV < 10000 ; betaV += 10)
		{
			for (u0 = 250 ; u0 < 390 ; u0 += 10)
			{
				for (yh = 1 ; yh < 144 ; yh += 10) // 160 160 000 000 itérations (c'est beaucoup)
				{
					coefs[0] = betaU;
					coefs[1] = betaV;
					coefs[2] = u0;
					coefs[3] = yh;
					
					calcul_coord_plan(cImage, NB_POINTS, coefs, nouvCoords);
					
					calcul_distances(nouvCoords, NB_POINTS, distances, NB_SEGMENTS);
					
					erreur = somme_erreurs(distancesPlan, distances, NB_SEGMENTS);
					if ( fabs(erreur) < fabs(solution[4]) )
					{
						solution[0] = betaU;
						solution[1] = betaV;
						solution[2] = u0;
						solution[3] = yh;
						solution[4] = erreur;
						
						printf("%f , %f, %f, %f, %f\n", solution[4], solution[0], solution[1], solution[2], solution[3]);
					}
					
				}
			}
		}
	}
	printf("\n");
	
	// Rebouclage plus fin.
	// On fait attention à ne pas sorir des limites.
	betaUm = solution[0] - 50;
	if (betaUm < 0) betaUm = 0.0;
	betaUM = solution[0] + 50;
	if (betaUM > 1200) betaUM = 1200;
	
	betaVm = solution[1] - 50;
	if (betaVm < 1000) betaVm = 1000.0;
	betaVM = solution[1] + 50;
	if (betaVM > 5000) betaVM = 5000.0;
	
	u0m = solution[2] - 50;
	if (u0m < 250) u0m = 250.0;
	u0M = solution[2] + 50;
	if (u0M > 390) u0M = 390.0;
	
	yhm = solution[3] - 50;
	if (yhm < 1) yhm = 1.0;
	yhM = solution[3] + 50;
	if (yhM > 144) yhM = 144;
	
	for (betaU = betaUm ; betaU < betaUM ; betaU ++)
	{
		for (betaV = betaVm ; betaV < betaVM ; betaV ++)
		{
			for (u0 = u0m ; u0 < u0M ; u0 ++)
			{
				for (yh = yhm ; yh < yhM ; yh ++) 
				{
					coefs[0] = betaU;
					coefs[1] = betaV;
					coefs[2] = u0;
					coefs[3] = yh;
					
					calcul_coord_plan(cImage, NB_POINTS, coefs, nouvCoords);
					
					calcul_distances(nouvCoords, NB_POINTS, distances, NB_SEGMENTS);
					
					erreur = somme_erreurs(distancesPlan, distances, NB_SEGMENTS);
					
					if ( fabs(erreur) < fabs(solution[4]) )
					{
						solution[0] = betaU;
						solution[1] = betaV;
						solution[2] = u0;
						solution[3] = yh;
						solution[4] = erreur;
						
						//printf("%f\n", solution[4]);
						printf("%f , %f, %f, %f, %f\n", solution[4], solution[0], solution[1], solution[2], solution[3]);
					}
					
				}
			}
		}
	}
	
	// On a les "bon" coefficient BETAU, BETAV, UO et YH.
	// On cherche les coordonnees de la camera.
		
	printf("\n");
	printf("coordonnees : \n");
	calcul_coord_plan(cImage, NB_POINTS, solution, nouvCoords);
	for (i = 0 ; i < NB_POINTS ; i++)
	{
		printf("%f, %f \t\t %f,%f\n", cPlan[i].x, cPlan[i].y, nouvCoords[i].x, nouvCoords[i].y);		
	}
	printf("\n");
	
	// Calculs des distances.
	distance = calcul_distances(nouvCoords, NB_POINTS, distances, NB_SEGMENTS);		
	printf ("somme erreur : %f", solution[4]);
	printf("\n");
	
	// Calculs des pentes.
	calcul_pentes(nouvCoords, NB_POINTS, pentesImage, NB_SEGMENTS);		
	calcul_angles(pentesImage, NB_SEGMENTS, anglesImage);
	printf("\nangles : \n");
	for (i = 0 ; i < NB_SEGMENTS ; i++)
	{		
		printf("%f\t\t%f\n", anglesPlan[i] * 180 / PI, anglesImage[i] * 180 / PI);		
	}
	printf("\n");
	
	printf("Diff des angles une à une = \n");	
	for (i = 0 ; i < NB_SEGMENTS ; i++)
	{		
		moyAngles += anglesPlan[i] - anglesImage[i]	;
		printf("%f\n", (anglesPlan[i] - anglesImage[i]) * 180 / PI);
	}
	// Moyenne de difference de angles.	
	moyAngles /= NB_SEGMENTS;
		
	printf("\nangle : %f rad : %f deg\n", moyAngles, moyAngles * 180 / PI);
	angle = moyAngles;
	
	
	
	/***********************************
     *
     *        DONNEES EN SORTIE
     *
     ***********************************/
	
	printf("\n\nRECAPITULATIF : \n");
	printf("BetaU : %f\n", solution[0]);
	printf("BetaV : %f\n", solution[1]);
	printf("u0    : %f\n", solution[2]);
	printf("yh    : %f\n", solution[3]);
	printf("angle : %f rad; %f deg\n", moyAngles, moyAngles * 180 / PI);
	printf("---------------------------\n");
	
	// On regarde maintenant pour la position de la camera.
	// Matrice de changement de repere.	
	// Avec le 2nd point.
	camera.x = cPlan[1].x - (nouvCoords[1].x * cos(angle) - nouvCoords[1].y * sin(angle));
	camera.y = cPlan[1].y - (nouvCoords[1].x * sin(angle) + nouvCoords[1].y * cos(angle));
				
	printf("\ncamera : %f, %f \n", camera.x, camera.y);
	
			
	return 32;
}













