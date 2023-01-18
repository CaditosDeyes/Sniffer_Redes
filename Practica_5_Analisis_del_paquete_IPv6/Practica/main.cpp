#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;
int binario[8];

int potencias[8] = {1, 2, 4, 8, 16, 32, 64, 128};
int potencias2[8] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

int limpiarBinario(){
    for(int i=7; i>=0; i--)
        binario[i]=0;
    return 0;
}
int imprimirBinario(){
    cout << "\nNumero en binario: ";
    for(int i=7; i>=0; i--)
        cout << binario[i];
    cout << endl;
    return 0;
}
int bin_dec(){
    int num=0;
    for(int i=7; i>=0; i--)
        num = num + (binario[i]*potencias[i]);
    return num;
}

void tipoServicioPrioridad(int prioridad){
    int aux = 4;
    // Bits de 0 a 2: Prioridad
    cout << "\nTipo de servicio: ";
    switch(prioridad){
        case 0:
            cout << "Prioridad De rutina" << endl;
            break;
        case 1:
            cout << "Prioritario" << endl;
            break;
        case 2:
            cout << "Inmediato" << endl;
            break;
        case 3:
            cout << "Relampago" << endl;
            break;
        case 4:
            cout << "Invalidacion Relampago" << endl;
            break;
        case 5:
            cout << "Procesando llamada crÃ­tica y de emergencia" << endl;
            break;
        case 6:
            cout << "Control de trabajo de Internet" << endl;
            break;
        case 7:
            cout << "Control de red" << endl;
            break;
        default:
            cout << "Se ha producido un error" << endl;
            break;
    }
    // Desglose de bits

    // Bit 3: Retardo
    if(binario[aux])
        cout << endl << "Retardo bajo";
    else
        cout << endl << "Retardo normal";
    aux--;
    //Bit 4: Rendimiento. 0= normal; 1= alto.
    if(binario[aux])
        cout << endl << "Rendimiento alta";
    else
        cout << endl << "Rendimiento normal";
    aux--;
    //Bit 5: Fiabilidad. 0=normal; 1= alta.
    if(binario[aux])
        cout << endl << "Fiabilidad alta";
    else
        cout << endl << "Fiabilidad normal";
    aux--;
    //Bit 6-7: No usados. Reservados para uso futuro.
    cout << endl;
}

int byte1_LTI(){
    int byte1=0;
    for(int i=7; i>=0; i--){
        byte1 = byte1 + binario[i]*potencias2[i];
        //cout << byte1 << " = " << binario[i] << " * " << potencias2[i] << endl;
        //system("PAUSE");
    }
    return byte1;
}

int byte2_LTI(){
    int byte2=0;
    for(int i=7; i>=0; i--){
        byte2 = byte2 + binario[i]*potencias[i];
        //cout << byte2 << " = " << binario[i] << " * " << potencias[i] << endl;
        //system("PAUSE");
    }
    return byte2;
}

// Banderas
// Posicion de Fragmento
int bandera3bits(){
    int i=7, suma=0;
     cout<<"Bit 0: Reservado\n";
        i--;
        if(binario[i]==0)
            cout<<"Bit 1: Reservado\n";
        else
            cout<<"Bit 1: No divisible\n";
        i--;
        if(binario[i]==0)
            cout<<"Bit 2: Ultimo Fragmento\n";
        else
             cout<<"Bit 2: Fragmento Intermedio\n";
        i--;
        // i=4
        for(i; i>=0; i--)
            suma = suma + (binario[i]*potencias2[i]);
        return suma;
}

// Tiempo de vida = bin_dec
// Protocolo = bin_dec

void mensajeInformativo(int mensaje){
    cout << "Mensaje informativo: ";
    switch(mensaje){
        case 0:
            cout << "Echo Reply (respuesta de eco)";
            break;
        case 3:
            cout << "Destination Unreacheable (destino inaccesible)";
            break;
        case 4:
            cout << "Source Quench (disminuciÃ³n del trÃ¡fico desde el origen)";
            break;
        case 5:
            cout << "Redirect (redireccionar - cambio de ruta)";
            break;
        case 8:
            cout << "Echo (solicitud de eco)";
            break;
        case 11:
            cout << "Time Exceeded (tiempo excedido para un datagrama)";
            break;
        case 12:
            cout << "Parameter Problem (problema de parametros";
            break;
        case 13:
            cout << "Timestamp (solicitud de marca de tiempo)";
            break;
        case 14:
            cout << "Timestamp Reply (respuesta de marca de tiempo)";
            break;
        case 15:
            cout << "Information Request (solicitud de informaciÃ³n) - obsoleto-";
            break;
        case 16:
            cout << "Information Reply (respuesta de informacion) - obsoleto-";
            break;
        case 17:
            cout << "Addressmask (solicitud de mascara de direccion)";
            break;
        case 18:
            cout << "Addressmask Reply (respuesta de mascara de direccion";
            break;
    }
}

// Codigo de error

void codigoError(int codigo){
    cout << "\nCodigo de error: ";
    switch(codigo){
        case 0:
            cout << "no se puede llegar a la red";
            break;
        case 1:
            cout << "no se puede llegar al host o aplicaciÃ³n de destino";
            break;
        case 2:
            cout << "el destino no dispone del protocolo solicitado";
            break;
        case 3:
            cout << "no se puede llegar al puerto destino o la aplicaciÃ³n destino no esta libre";
            break;
        case 4:
            cout << "se necesita aplicar fragmentacion, pero el flag correspondiente indica lo contrario";
            break;
        case 5:
            cout << "la ruta de origen no es correcta";
            break;
        case 6:
            cout << "no se conoce la red destino";
            break;
        case 7:
            cout << "no se conoce el host destino";
            break;
        case 8:
            cout << "el host origen esta aislado";
            break;
        case 9:
            cout << "la comunicacion con la red destino esta prohibida por razones administrativas";
            break;
        case 10:
            cout << "la comunicacion con el host destino esta prohibida por razones administrativas";
            break;
        case 11:
            cout << "no se puede llegar a la red destino debido al Tipo de servicio";
            break;
        case 12:
            cout << "no se puede llegar al host destino debido al Tipo de servicio";
            break;
    }
}

int main(){
    FILE*archivo;
    unsigned char palabra;
    int i=0, aux=0, band=0, tamanio=0, version=0, prioridad=0, sumaLTI=0, prot=0, frag=0, dec16=0, sum1=0, sum2=0, auxsum=0;

    if ((archivo = fopen("ethernet_ipv6_nd.bin", "rb+")) == NULL){
        printf ( "Error en la apertura. Es posible que el fichero no exista \n ");
    }
    else{

        //palabra = fgetc (archivo);
        cout << "DIRECCION ORIGEN\n";
        for(int i=0; i<=5; i++){
            if(i<5){
                palabra = fgetc(archivo);
                printf("%0.2X:", palabra);
            }
            else{
                palabra = fgetc(archivo);
                printf("%0.2X", palabra);
            }
        }

        cout << "\n\n";

        cout << "DIRECCION DESTINO\n";
        for(int i=0; i<=5; i++){
            if(i<5){
                palabra = fgetc(archivo);
                printf("%0.2X:", palabra);
            }
            else{
                palabra = fgetc(archivo);
                printf("%0.2X", palabra);
            }
        }

        cout << "\n\n";

        cout << "TIPO\n";
        for(int i=0; i<=1; i++){
            palabra = fgetc(archivo);
            printf("%0.2X:", palabra);
        }

        switch(palabra){
            case 0:
            // IPv4 caracteristicas -> REALIZADO
                printf("\n\nPaquete IPv4\n");
                palabra = fgetc(archivo);

                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

            // Version y TamaÃ±o (1 byte) -> REALIZADO
                for(int i=0; i<=7; i++){
                    if(i<=3)
                        tamanio = (binario[i]*potencias[i])+tamanio;
                    else
                        version = (binario[i]*potencias[i-4])+version;
                }

                cout << "\nVersion: " << version << "\nTamanio: " << tamanio << endl;

            // Tipo de servicios 8 bits
                limpiarBinario();
                palabra = fgetc(archivo); // 00 del archivo
                //palabra = fgetc(archivo); // 00 del archivo
                //palabra = fgetc(archivo); // 3C del archivo
                //printf("palabra actual %0.2X", palabra);

                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                //imprimirBinario();

                for(int i=5; i<=7; i++)
                    prioridad = (binario[i]*potencias[i-5])+prioridad;

                tipoServicioPrioridad(prioridad);

                // Longitud total e identificador: Palabras 00:3C

                for(int j=0; j<=1; j++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();

                    sumaLTI = byte1_LTI();

                    palabra = fgetc(archivo); // 3c-09
                    //printf("\nPalabra2: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();

                    sumaLTI = sumaLTI + byte2_LTI();

                    if(band==0){
                        cout << "\nLongitud total: " << sumaLTI << " bytes";
                        band = 1;
                    }
                    else{
                        cout << "\nIdentificador: " << sumaLTI << endl;
                    }

                    sumaLTI = 0;
                }

                // Banderas y fragmento
                //conversion a binario banderas
                    palabra = fgetc(archivo); // 40
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                cout<<"\nBanderas" << endl;
                frag = bandera3bits();
                cout<<" "<<endl;

                palabra = fgetc(archivo); // 00
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                frag = frag + byte2_LTI();

                cout << "Posicion de fragmento: " << frag << endl;


                // Tiempo de vida

                palabra = fgetc(archivo); //40 - Tiempo de vida

                //printf("\nPalabra: %0.2x\n", palabra);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                cout << "\nTiempo de vida: " << bin_dec();
                limpiarBinario();

                // Protocolo
                palabra = fgetc(archivo); //06 - Protocolo
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                prot = bin_dec();
                cout << "\n\nProtocolo: ";
                switch(prot){
                    case 1:
                        cout << "ICMPv4\n";
                        fseek(archivo, 34, 0);

                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        mensajeInformativo(bin_dec());

                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        codigoError(bin_dec());

                        // Checksum
                        palabra = fgetc(archivo); //A8 - Checksum
                        printf("\nChecksum ICMPv4: %0.2X:", palabra);
                        palabra = fgetc(archivo); // 82
                        printf("%0.2X", palabra);

                        break;
                    case 6:
                        cout << "TCP\n";
                        break;
                    case 17:
                        cout << "UDP\n";
                        break;
                    case 58:
                        cout << "ICMPv6\n";
                        break;
                    case 118:
                        cout << "STP\n";
                        break;
                    case 121:
                        cout << "SMP\n";
                        break;
                    default:
                        cout << "Protocolo no reconocido\n";
                        break;
                }
                //cout << "\nProtocolo: " << bin_dec();
                limpiarBinario();

                // Checksum
                palabra = fgetc(archivo); //A8 - Checksum
                printf("\n\nChecksum: %0.2X:", palabra);
                palabra = fgetc(archivo); // 82
                printf("%0.2X", palabra);

                // Direccion IP origen = AC:16:C8:02
                cout << "\n\nDireccion IP origen: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // AC:16:C8:02
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }
                // Direccion IP destino = D0:5E:F6:B8
                cout << "\nDireccion IP destino: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // D0:5E:F6:B8
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }
                break;
            case 6:
                printf("\tARP\n");
                //Aqui va todo el desmadre
                //Tipo de hardware
                //convertir a binario
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = byte2_LTI();
                }
                cout << "\nTipo de Hardware: " << dec16 << endl;
                dec16 = 0;


                printf("\nTipo de protocolo: ");
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo);
                    printf("%0.2X:", palabra);
                }

                printf("\nLongitud de hardware(x):");
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    cout<<" "<<bin_dec()<<endl;

                printf("\nLongitud de protocolo(y):");
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    cout<<" "<<bin_dec()<<endl;

                //Codigo de operacion
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = byte2_LTI();
                }
                cout << "\nCodigo de operacion: " << dec16;
                switch(dec16){
                    case 1:
                        cout << "\tSolicitud ARP" << endl;
                    break;
                    case 2:
                        cout << "\tRespuesta ARP" << endl;
                    break;
                    case 3:
                        cout << "\tSolicitud RARP" << endl;
                    break;
                    case 4:
                        cout << "\tRespuesta RARP" << endl;
                    break;
                }

                // MAC EMISOR
                cout << "\nDIRECCION HARDWARE EMISOR: ";
                for(int i=0; i<=5; i++){
                    palabra = fgetc(archivo);
                    if(i<5)
                        printf("%0.2X:", palabra);
                    else
                        printf("%0.2X", palabra);
                }

                // IP
                // Direccion IP origen = AC:16:C8:02
                cout << "\nDIRECCION IP EMISOR: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // AC:16:C8:02
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }

                // MAC RECEPTOR
                cout << "\nDIRECCION HARDWARE RECEPTOR: ";
                for(int i=0; i<=5; i++){
                    palabra = fgetc(archivo);
                    if(i<5)
                        printf("%0.2X:", palabra);
                    else
                        printf("%0.2X", palabra);
                }

                // IP EMISOR
                // Direccion IP destino = D0:5E:F6:B8
                cout << "\nDIRECCION IP RECEPTOR: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // D0:5E:F6:B8
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }

                break;
            case 53:
                printf("\tRARP\n");
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = byte2_LTI();
                }
                cout << "\nTipo de Hardware: " << dec16 << endl;


                printf("\nTipo de protocolo: ");
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo);
                    printf("%0.2X:", palabra);
                }

                printf("\nLongitud de hardware(x):");
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    cout<<" "<<bin_dec()<<endl;

                printf("\nLongitud de protocolo(y):");
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    cout<<" "<<bin_dec()<<endl;

                //Codigo de operacion
                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = byte2_LTI();
                }
                cout << "\nCodigo de operacion: " << dec16;
                switch(dec16){
                    case 1:
                        cout << "\tSolicitud ARP" << endl;
                    break;
                    case 2:
                        cout << "\tRespuesta ARP" << endl;
                    break;
                    case 3:
                        cout << "\tSolicitud RARP" << endl;
                    break;
                    case 4:
                        cout << "\tRespuesta RARP" << endl;
                    break;
                }

                // MAC EMISOR
                cout << "\nDIRECCION HARDWARE EMISOR: ";
                for(int i=0; i<=5; i++){
                    palabra = fgetc(archivo);
                    if(i<5)
                        printf("%0.2X:", palabra);
                    else
                        printf("%0.2X", palabra);
                }

                // IP
                // Direccion IP origen = AC:16:C8:02
                cout << "\nDIRECCION IP EMISOR: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // AC:16:C8:02
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }

                // MAC RECEPTOR
                cout << "\nDIRECCION HARDWARE RECEPTOR: ";
                for(int i=0; i<=5; i++){
                    palabra = fgetc(archivo);
                    if(i<5)
                        printf("%0.2X:", palabra);
                    else
                        printf("%0.2X", palabra);
                }

                // IP EMISOR
                // Direccion IP destino = D0:5E:F6:B8
                cout << "\nDIRECCION IP RECEPTOR: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // D0:5E:F6:B8
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);

                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }
                break;
            case 221:
                printf("\tIPv6\n");
                //Aqui va todo el desmadre
                palabra = fgetc(archivo);
                //Version
                for(int i=7; i>=0; i--){
                    binario[i] = ((palabra & (1 << i)) ? 1:0);
                    if(i>=4)
                        sum1 = sum1 + binario[i]*potencias[i-4];
                    else
                        sum2 = sum2 + binario[i]*potencias[i];
                }
                //imprimirBinario();
                cout << "\nVersion: " << sum1 << endl;
                sum1=0;
                auxsum = sum2;
                sum2 = 0;
                // TrÃ¡fico
                palabra = fgetc(archivo);
                for(int i=7; i>=0; i--){
                    binario[i] = ((palabra & (1 << i)) ? 1:0);
                    if(i>=4)
                        sum1 = sum1 + binario[i]*potencias[i-4];
                    else
                        sum2 = sum2 + binario[i]*potencias[i];
                }
                cout << "\nTrafico";
                tipoServicioPrioridad(auxsum+sum1);
                //imprimirBinario();

                // Etiqueta de flujo

                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = dec16 + byte2_LTI();
                }
                cout << "\nEtiqueta de flujo: " << dec16+sum2 << endl;

                // TamaÃ±o de datos

                for(int i=0; i<=1; i++){
                    palabra = fgetc(archivo);
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    if(i==0)
                        dec16 = byte1_LTI();
                    else
                        dec16 = dec16 + byte2_LTI();
                }
                cout << "\nTamanio de datos: " << dec16 << endl;
                // Encabezado siguiente
                aux = 0;
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                aux = bin_dec();
                cout << "\nEncabezado siguiente: ";
                switch(aux){
                    case 1:
                        cout << "ICMPv4\n";
                        break;
                    case 6:
                        cout << "TCP\n";
                        break;
                    case 17:
                        cout << "UDP\n";
                        break;
                    case 58:
                        cout << "ICMPv6\n";
                        break;
                    case 118:
                        cout << "STP\n";
                        break;
                    case 121:
                        cout << "SMP\n";
                        break;
                    default:
                        cout << "Protocolo no reconocido\n";
                        break;
                }
                // LÃ­mite de salto
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);
                cout << "Limite de salto: " << bin_dec() << endl;

                // Direcciones IPv6
                cout << "\n\nDireccion IP origen: ";
                for(int i=0; i<=8; i++){
                    if(i<8){
                        palabra = fgetc(archivo);
                        printf("%0.4x:", palabra);
                    }
                    else{
                        palabra = fgetc(archivo);
                        printf("%0.4x", palabra);
                    }
                }
                cout << "\n\nDireccion IP destino: ";
                for(int i=0; i<=8; i++){
                    if(i<8){
                        palabra = fgetc(archivo);
                        printf("%0.4x:", palabra);
                    }
                    else{
                        palabra = fgetc(archivo);
                        printf("%0.4x", palabra);
                    }
                }
                break;
        }

        cout << "\n\nDATOS\n";
        while(!feof(archivo)){
            palabra = fgetc(archivo);
            printf(":%0.2X", palabra);
            //break;
        }
    }

    cout << endl << endl << endl << endl;
    return 0;
}
