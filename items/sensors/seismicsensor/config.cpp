class CfgPatches
{
    class seismicsensor 
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]={"A3_Characters_F"};
    }
}


class CfgMagazines
{
    class CA_Magazine;
    class colsog_inv_sensor: CA_Magazine
    {
        author = "Gerard";
        mass = 15;
        scope = 2;
        value = 1;
        displayName = "Seismic sensor";
        picture = "\seismicsensor\icons\icon.paa";
        model = "\seismicsensor\objects\seismicsensor.p3d";
        type = 256;
        count = 1;
        initSpeed = 18;
        nameSound = "handgrenade";
        maxLeadSpeed = 6.94444;
        descriptionShort = "Seismic sensor";
        displayNameShort = "Seismic sensor";
    };
};

class CfgVehicles 
{
    class Thing;
    class colsog_thing_sensor : Thing  
    {
        access = 0;
        scope = 2;
        model = "\seismicsensor\objects\seismicsensor.p3d";
        displayName = "Seismic sensor";
        faction = "Default";
        vehicleClass = "Objects";
        simulation = "thing";
        scopecurator = 2;
        author = "Gerard";
        destrType = "DestructNo";
    };
};