$fn=100;
//size box
boxx = 150;
boxy = 79;
boxz = 30;
boxzClose = 5;

//size for element in the box
wall = 1.5;
wall_adjusting = 1.5;
lenght_for_pcb = 5;
is = 0.1; //Przesuniecie punktu

//size for plug in the module
plug_x = 45;
plug_y = 18;
plug_z = 23;

//cut for hole in the box for plug
plug_boxx = 47 - (wall_adjusting/2);
plug_boxy = -3.1;
plug_boxz = 2.8 + lenght_for_pcb;


// mounting back case
screw_dz  =  5;        // height of the standoff
screw_dr  = 2.5;       // 5 mm diameter
screw_z = 5;  // depth of srew hole
screw_r = 1.5;       // 3 mm hole size


//BoxModule();

translate([0, 0, 31.5]){
    //Module();
//    BoxModuleClose();
}
cutClose();

module BoxModule(){
    difference(){
        minkowski(){
            cube([boxx,boxy,boxz]);
            cylinder(r=3, h=1);
        }
        // empty the inside of the box
        translate([wall,wall,wall]){
            minkowski(){
                cube([boxx-2*wall,boxy-2*wall,boxz+20]); 
                cylinder(r=3, h=1);
            }
        }
        // Cut for hole in the box
        translate([plug_boxx, plug_boxy, plug_boxz]){
            cube([plug_x + wall_adjusting, plug_y + wall_adjusting, plug_z + wall_adjusting]);
        }
    }
    translate([-1, -1, 0]){
        screwBox();
    }
    translate([151, -1, 0]){
        rotate([0, 0, 90]){
            screwBox();
        }
    }
    translate([-1, 81, 0]){
        rotate([0, 0, 270]){
            screwBox();
        }
    }
    translate([151, 81, 0]){
        rotate([0, 0, 180]){
            screwBox();
        }
    }
}

module screwBox(){
    difference(){
        translate([0,0,0]){
            minkowski(){
                cube([3,3,5]);
                cylinder(r=1, h=1);
            }
        }
        //translate([0,0,0]){
          //  cylinder(r=screw_dr,h=screw_dz+wall);
        //}
        translate([2,2,1]){ 
            cylinder(r=screw_r,h=screw_z+0.1);
        }
        
    }
}



//module
module cable(){
    color("blue");
    cube([21.5,12.6,8.5]);
    translate([21.5,2.4,0]){
        cube([11,7.5,7.4]);
        }
    }
    
module mount_USB_cable(){
    translate([0,0,0,]){
        translate([0,0,0]){
            cube([2,22,4]);
        }
        translate([2,0,0]){
            cube([30,22,2]); // Podstawka
        }   
        //mocowanie usbIn    
        translate([6+is,1.8,2-is]){
            color("green")
            cube([12,2,3]);    
        }
        translate([12+is,16.8,2-is]){
            color("green")
            cube([13,2,3]);
        }
        translate([23.7+is,14,2-is]){
            color("green")
            cube([1.8,4.8,3]);
        }    
        translate([2+is,4,2]){
            color("blue")
            cable();
        }
    }
        
}

module Module(){
    color ("red")
    cube([boxx,boxy,boxz - 28]);
    translate([47, -9, 2]){
        color ("blue")
        cube([plug_x, plug_y, plug_z]);
    }
}

module BoxModuleClose(){
   // color ("red")
    //rotate([0, 180, 0])
    difference(){
        minkowski(){
            cube([boxx,boxy,boxzClose-3]);
            cylinder(r=3, h=1);
        }
        // empty the inside of the box
        translate([wall+0.3,wall+0.3, -1]){
            minkowski(){
                cube([boxx-2.6*wall,boxy-2.6*wall,boxzClose+2]); 
                cylinder(r=3, h=1);
            }
        }
        translate([wall - 3 ,wall, - 1]){
            cutClose();
        }
    }
}

module cutClose(){
    color ("red")
    difference(){
        translate([wall,wall-3, 0]){
            minkowski(){
                cube([boxx + 1, boxy + 1, 2]); 
                cylinder(r=3, h=1);
            }
        }
        translate([wall + 1.4,wall - 1.6, -1]){
            minkowski(){
                cube([boxx - 2.8 ,boxy - 3 ,boxzClose]); 
                cylinder(r=3, h=1);
            }
        }
    }
}

