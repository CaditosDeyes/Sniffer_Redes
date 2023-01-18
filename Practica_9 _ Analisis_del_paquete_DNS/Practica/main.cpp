#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
int binario[8];

int potencias[8] = {1, 2, 4, 8, 16, 32, 64, 128};
int potencias2[8] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
long long int potencias3[8] = {65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608};
long long int potencias4[8] = {16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648};

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
    }
    return byte2;
}

long long int byte3_LTI(){
    long long int byte3=0;
    for(int i=7; i>=0; i--){
        byte3 = byte3 + binario[i]*potencias3[i];
    }
    return byte3;
}

long long int byte4_LTI(){
    long long int byte4=0;
    for(int i=7; i>=0; i--){
        byte4 = byte4 + binario[i]*potencias4[i];
    }
    return byte4;
}

// Banderas
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

void DescripcionIcmpv6Tipo1(int mensaje){ //tipo 1
    cout << "Valor/Descripcion del campo del codigo: ";
    switch(mensaje){
        case 0:
            cout << "No existe ruta de destino";
            break;
        case 1:
            cout << "Comunicacion con el destino aministrativamente inalcanzable";
            break;
        case 2:
            cout << "No asignado";
            break;
        case 3:
            cout << "Direccion inalcanzable";
            break;
    }
}

void DescripcionIcmpv6Tipo3(int mensaje){ //tipo 3
    cout << "\nValor/Descripcion del campo del codigo: ";
    switch(mensaje){
        case 0:
            cout << "Limite de salto excedido";
            break;
        case 1:
            cout << "Tiempo de reesamble de fragmento excedido";
            break;
    }
}

void DescripcionIcmpv6Tipo4(int mensaje){ //tipo 4
    cout << "\nValor/Descripcion del campo del codigo: ";
    switch(mensaje){
        case 0:
            cout << "El campo del encabezado erroneo encontro";
            break;
        case 1:
            cout << "El tipo siguiente desconocido de la cabeza encontro";
            break;
        case 2:
            cout << "Opcion desconocida del ipv6 encontrada";
            break;
    }
}

//Mensaje informativo icmpv6
void mensajeErrorIcmpv6(int mensaje){
    cout << "\nMensaje de error: ";
    switch(mensaje){
        case 1:
            cout << "Mensaje de destino inalcanzable";
            break;
        case 2:
            cout << "Mensaje de paquete demasiado grande";
            break;
        case 3:
            cout << "Time Exceeded Message";
            break;
        case 4:
            cout << "Mensaje de problema de parametro";
            break;
        case 128:
            cout << "Mensaje del pedido de eco";
            break;
        case 129:
            cout << "Mensaje de respuesta de eco";
            break;
        case 133:
            cout << "Mensaje de solicitud del router";
            break;
        case 134:
            cout << "Mensaje de anuncio del router";
            break;
        case 135:
            cout << "Mensaje de solicitud de vecino";
            break;
        case 136:
            cout << "Mensaje de anuncio de vecino";
            break;
        case 137:
            cout << "Reortiente el mensaje";
            break;
    }
}


void banderasTCP(){
    for(int i=7; i>=0; i--){
        if(i==7)
            cout << "CWR : " << binario[i] << endl;
        else if(i==6)
            cout << "ECE : " << binario[i] << endl;
        else if(i==5)
            cout << "URG : " << binario[i] << endl;
        else if(i==4)
            cout << "ACK : " << binario[i] << endl;
        else if(i==3)
            cout << "PSH : " << binario[i] << endl;
        else if(i==2)
            cout << "RST : " << binario[i] << endl;
        else if(i==1)
            cout << "SYN : " << binario[i] << endl;
        else
            cout << "FIN : " << binario[i] << endl;
    }
}

int puertos(int dec16){
    int caso = 0;
    if(dec16<=1023){
        cout << "Puertos bien conocidos\n";
        switch(dec16){
            case 20:
                cout << "Servicio FTP" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 20;
                break;
            case 21:
                cout << "Servicio FTP" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 21;
                break;
            case 22:
                cout << "Servicio SSH" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 22;
                break;
            case 23:
                cout << "Servicio TELNET" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 23;
                break;
            case 25:
                cout << "Servicio SMTP" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 25;
                break;
            case 53:
                cout << "Servicio DNS" << endl;
                cout << "Â¨Protoloco TCP/UDP" << endl;
                caso = 53;
                break;
            case 67:
                cout << "Servicio DHCP" << endl;
                cout << "Â¨Protoloco UDP" << endl;
                caso = 67;
                break;
            case 68:
                cout << "Servicio DHCP" << endl;
                cout << "Â¨Protoloco UDP" << endl;
                caso = 68;
                break;
            case 69:
                cout << "Servicio TFTP" << endl;
                cout << "Â¨Protoloco UDP" << endl;
                caso = 69;
                break;
            case 80:
                cout << "Servicio HTTP" << endl;
                cout << "Â¨Protoloco UDP" << endl;
                caso = 80;
                break;
            case 110:
                cout << "Servicio POP3" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 110;
                break;
            case 143:
                cout << "Servicio IMAP" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 143;
                break;
            case 443:
                cout << "Servicio HTTPS" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 443;
                break;
            case 993:
                cout << "Servicio IMAP SSL" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 993;
                break;
            case 995:
                cout << "Servicio POP SSL" << endl;
                cout << "Â¨Protoloco TCP" << endl;
                caso = 995;
                break;
        }
    }
    else if(dec16<=49151 and dec16>=1024)
        cout << "Puertos registrados\n";
    else if(dec16<=65535 and dec16>=49152)
        cout << "Puertos dinamicos o privados\n";
    else
        cout << "Â¡Â¡Â¡Â¡Â¡Â¡Â¡ERROR!!!!!!!!" << endl;

    return caso;
}

int puertosUDP(int dec16){
    int caso = 0;
    if(dec16<=1023){
        cout << "Puertos bien conocidos\n";
        switch(dec16){
            case 53:
                cout << "Servicio DNS" << endl;
                cout << "Protoloco TCP/UDP" << endl;
                caso = 53;
                break;
            case 67:
                cout << "Servicio DHCP" << endl;
                cout << "Protoloco UDP" << endl;
                caso = 67;
                break;
            case 68:
                cout << "Servicio DHCP" << endl;
                cout << "Protoloco UDP" << endl;
                caso = 68;
                break;
            case 69:
                cout << "Servicio TFTP" << endl;
                cout << "Protoloco UDP" << endl;
                caso = 69;
                break;
            case 80:
                cout << "Servicio HTTP" << endl;
                cout << "Protoloco UDP" << endl;
                caso = 80;
                break;
        }
    }
    else if(dec16<=49151 and dec16>=1024)
        cout << "Puertos registrados\n";
    else if(dec16<=65535 and dec16>=49152)
        cout << "Puertos dinamicos o privados\n";
    else
        cout << "Â¡Â¡Â¡Â¡Â¡Â¡Â¡ERROR!!!!!!!!" << endl;

    return caso;
}

// Banderas
int banderas16_1(){
    int i=7, suma=0, j=3, campR=0;
    if(binario[i]==0){
        cout<<"\nConsulta(0)\n";
        campR = binario[i];
    }
    else{
        cout<<"\nRespuesta(1)\n";
        campR = binario[i];
    }
    i--; // i=6

    while(j>=0){
        suma = suma+(binario[i]*potencias[i]);
        i--;
        j--;
    } // i=2

    if(i==2){
        switch(suma){
        case 0:
            cout << "Consulta estandar(QUERY).\n";
            break;
        case 1:
            cout << "Consulta inversa(IQUERY).\n";
            break;
        case 2:
            cout << "Solicitud del estado del servidor(STATUS).";
            break;
        default:
            break;
        }
    }

    cout<<"\nAA: " << binario[i];
    i--; // i = 1
    cout<<"\nTC: " << binario[i];
    i--; // i = 0
    cout<<"\nRD: " << binario[i];
    i--; // i no puede decrementar

    return campR;
}

void banderas16_2(){
    int i=7, suma=0, j=3;
    cout<<"\nRA: " << binario[i];
    i--; // i = 6
    cout<<"\nZ: " << 0;
    i = i-3; // i = 3
    while(j>=0){
        suma = suma + (binario[i]*potencias[i]);
        j--;
        i--;
    }
    cout << endl;
    switch(suma){
        case 0:
            cout << "Ningun error.\n";
            break;
        case 1:
            cout << "Error de formato.\n";
            break;
        case 2:
            cout << "Fallo en el servidor.\n";
            break;
        case 3:
            cout << "Error de nombre.\n";
            break;
        case 4:
            cout << "No implementado.\n";
            break;
        case 5:
            cout << "Rechazado.\n";
            break;
        default:
            break;
        } // i = 0
}

// DNS
int tipoDNS(int tipo){
    cout << "\nTipo: ";
    switch(tipo){
        case 1:
            cout << "A.";
            break;
        case 5:
            cout << "CNAME.\n";
            break;
        case 13:
            cout << "HINFO.\n";
            break;
        case 15:
            cout << "MX.\n";
            break;
        case 22:
            cout << "NS.\n";
            break;
        case 23:
            cout << "NS.\n";
            break;
        default:
            cout << "ERROR EN TIPO\n";
            break;
    }
    return 0;
}

void claseDNS(int clase){
    cout << "\nClase: ";
    switch(clase){
        case 1:
            cout << "IN.";
            break;
        case 3:
            cout << "CH.\n";
            break;
        default:
            cout << "ERROR EN CLASE\n";
            break;
    }
}

void rdata(int longDatos){
    switch(longDatos){
        case 1:
            cout << "A.";
            break;
        case 2:
            cout << "CNAME.\n";
            break;
        case 3:
            cout << "MX.\n";
            break;
        case 4:
            cout << "NS.\n";
            break;
        case 5:
            cout << "PTR.\n";
            break;
        case 6:
            cout << "SOA.\n";
            break;
        default:
            cout << "ERROR EN LONGITUD DE DATOS\n";
            break;
    }
}

int main(){
    FILE*archivo;
    unsigned char palabra;
    int i=0, aux=0, band=0, tamanio=0, version=0, prioridad=0, sumaLTI=0, prot=0, frag=0, dec8=0, dec16=0, sum1=0, sum2=0, auxsum=0, bit4dec=0, bit3dec=0, caso=0, auxflag=0, campoRespuesta=0;
    long long int dec32=0;

    if ((archivo = fopen("ethernet_ipv4_udp_dns.bin", "rb+")) == NULL){
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
                        cout << "\n---------------------\n";
                        cout << "TCP\n";
                        // Codigo
                        fseek(archivo, 34, 0);
                        // Puerto origen y destino
                        for(int j=0; j<=1; j++){
                            dec16 = 0;
                            for(int i=0; i<=1; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                if(i==0)
                                    dec16 = byte1_LTI();
                                else
                                    dec16 = dec16 + byte2_LTI();
                            }
                            if(j==0)
                                cout << "\nPuerto origen: " << dec16 << endl;
                            else
                                cout << "\nPuerto destino: " << dec16 << endl;
                                caso = puertos(dec16);
                        }
                        // Numero de secuencia (32 bits) y Numero de acuse de recibo (32 bits)
                        for(int i1=0; i1<=1; i1++){
                            dec32 = 0;
                            for(int i=0; i<=3; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                //printf("\nPalabra: %0.2x\n", palabra);
                                if(i==0)
                                    dec32 = byte4_LTI();
                                else if(i==1)
                                    dec32 = dec32 + byte3_LTI();
                                else if(i==2)
                                    dec32 = dec32 + byte1_LTI();
                                else
                                    dec32 = dec32 + byte2_LTI();
                            }

                            if(i1==0)
                                cout << "\nNumero de secuencia: " << dec32 << endl;
                            else
                                cout << "\nNumero de acuse de recibo: " << dec32 << endl;
                        }
                        // Longitud de cabecera
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        for(int i=7; i>=4; i--)
                            bit4dec = (binario[i]*potencias[i-4])+bit4dec;
                        cout << "\nLongitud de cabecera: " << bit4dec << endl;

                        for(int i=4; i>=0; i--){
                            if(i==0){
                                if((binario[i]*potencias[i])==0)
                                    cout << "\nBanderas:" << endl;
                                    cout << "\n NS : " << binario[i] << endl;
                            }
                            else
                                bit3dec = (binario[i]*potencias[i])+bit3dec;
                                if(i==1)
                                    cout << "\nReservado: " << bit3dec << endl;
                        }
                        // BANDERAS TCP
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        banderasTCP();

                        // TAMAÃ‘O DE VENTANA
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }

                        cout << "\nTamanio de ventana: " << dec16 << endl;

                        // CHECKSUM
                        palabra = fgetc(archivo);
                        printf("Checksum 11: %0.2X:", palabra);
                        palabra = fgetc(archivo);
                        printf("%0.2X", palabra);

                        // Puntero urgente
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }

                        cout << "\nPuntero urgente: " << dec16 << endl;

                        break;
                    case 17:
                        cout << "UDP\n";
                        cout << "\n-------------------------\n";
                        fseek(archivo, 34, 0);
                        // Puerto origen y destino
                        for(int j=0; j<=1; j++){
                            dec16 = 0;
                            for(int i=0; i<=1; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                if(i==0)
                                    dec16 = byte1_LTI();
                                else
                                    dec16 = dec16 + byte2_LTI();
                            }
                            if(j==0){
                                cout << "\nPuerto origen: " << dec16 << " : ";
                                caso = puertosUDP(dec16);
                            }
                            else{
                                cout << "\nPuerto destino: " << dec16 << " : ";
                                caso = puertosUDP(dec16);
                            }
                        }
                        // Longitud total
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }
                        cout << "\nLongitud Total: " << dec16 << endl;
                        // CHECKSUM UDP
                        palabra = fgetc(archivo);
                        printf("Checksum 22: %0.2X:", palabra);
                        palabra = fgetc(archivo);
                        printf("%0.2X", palabra);
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

                cout << "\n---------------------\n";
                // Checksum
                palabra = fgetc(archivo); //A8 - Checksum
                printf("\nChecksum 33: %0.2X:", palabra);
                palabra = fgetc(archivo); // 82
                printf("%0.2X", palabra);

                fseek(archivo, 34, 0);

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
                    palabra = fgetc(archivo);
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
                        // Codigo
                        fseek(archivo, 54, 0);
                        // Puerto origen y destino
                        for(int j=0; j<=1; j++){
                            dec16 = 0;
                            for(int i=0; i<=1; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                if(i==0)
                                    dec16 = byte1_LTI();
                                else
                                    dec16 = dec16 + byte2_LTI();
                            }
                            if(j==0)
                                cout << "\nPuerto origen: " << dec16 << endl;
                            else
                                cout << "\nPuerto destino: " << dec16 << endl;
                        }
                        // Numero de secuencia (32 bits) y Numero de acuse de recibo (32 bits)
                        for(int i1=0; i1<=1; i1++){
                            dec32 = 0;
                            for(int i=0; i<=3; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                //printf("\nPalabra: %0.2x\n", palabra);
                                if(i==0)
                                    dec32 = byte4_LTI();
                                else if(i==1)
                                    dec32 = dec32 + byte3_LTI();
                                else if(i==2)
                                    dec32 = dec32 + byte1_LTI();
                                else
                                    dec32 = dec32 + byte2_LTI();
                            }

                            if(i1==0)
                                cout << "\nNumero de secuencia: " << dec32 << endl;
                            else
                                cout << "\nNumero de acuse de recibo: " << dec32 << endl;
                        }
                        // Longitud de cabecera
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        for(int i=7; i>=4; i--)
                            bit4dec = (binario[i]*potencias[i-4])+bit4dec;
                        cout << "\nLongitud de cabecera: " << bit3dec << endl;

                        for(int i=4; i>=0; i--){
                            if(i==0){
                                if((binario[i]*potencias[i])==0)
                                    cout << "\nBanderas:" << endl;
                                    cout << "\n NS : " << binario[i] << endl;
                            }
                            else
                                bit3dec = (binario[i]*potencias[i])+bit3dec;
                                if(i==1)
                                    cout << "\nReservado: " << bit3dec << endl;
                        }
                        // BANDERAS TCP
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        banderasTCP();

                        // TAMAÃ‘O DE VENTANA
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }

                        cout << "\nTamanio de ventana: " << dec16 << endl;

                        // CHECKSUM
                        palabra = fgetc(archivo);
                        printf("Checksum: %0.2X:", palabra);
                        palabra = fgetc(archivo);
                        printf("%0.2X", palabra);

                        // Puntero urgente
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }

                        cout << "\nPuntero urgente: " << dec16 << endl;
                        break;
                    case 17:
                        cout << "UDP\n";
                        fseek(archivo, 54, 0);
                        // Puerto origen y destino
                        for(int j=0; j<=1; j++){
                            dec16 = 0;
                            for(int i=0; i<=1; i++){
                                palabra = fgetc(archivo);
                                for(int i=7;i>=0;i--)
                                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                                if(i==0)
                                    dec16 = byte1_LTI();
                                else
                                    dec16 = dec16 + byte2_LTI();
                            }
                            if(j==0)
                                cout << "\nPuerto origen: " << dec16 << " : ";
                            else{
                                cout << "\nPuerto destino: " << dec16 << " : ";
                                puertosUDP(dec16);
                            }
                        }
                        // Longitud total
                        dec16 = 0;
                        for(int i=0; i<=1; i++){
                            palabra = fgetc(archivo);
                            for(int i=7;i>=0;i--)
                                binario[i]=((palabra & (1 << i)) ? 1 : 0);

                            if(i==0)
                                dec16 = byte1_LTI();
                            else
                                dec16 = dec16 + byte2_LTI();
                        }
                        cout << "\nLongitud Total: " << dec16 << endl;
                        // CHECKSUM UDP
                        palabra = fgetc(archivo);
                        printf("Checksum: %0.2X:", palabra);
                        palabra = fgetc(archivo);
                        printf("%0.2X", palabra);
                        break;
                    case 58:
                        cout << "ICMPv6\n";
                        fseek(archivo, 54, 0);

                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);

                        mensajeErrorIcmpv6(bin_dec());
                        if(palabra == 1){
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);
                        cout << endl;
                        DescripcionIcmpv6Tipo1(bin_dec());
                        }
                        else if (palabra == 3){
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);
                        cout << endl;
                        DescripcionIcmpv6Tipo4(bin_dec());
                        }
                        else if (palabra == 4){
                        palabra = fgetc(archivo);
                        for(int i=7;i>=0;i--)
                            binario[i]=((palabra & (1 << i)) ? 1 : 0);
                        cout << endl;
                        DescripcionIcmpv6Tipo4(bin_dec());
                        }


                        // Checksum
                        palabra = fgetc(archivo); //A8 - Checksum
                        printf("\nChecksum ICMPv6: %0.2X:", palabra);
                        palabra = fgetc(archivo); // 82
                        printf("%0.2X", palabra);

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
                cout << "\nLimite de salto: " << bin_dec() << endl;

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
        // DNS CODIGO FACILITO PRO XXX_DNS777_XXX
        if(caso==53){
            //
            //cout << endl << "caso: " << caso;
            // ID (hexadecimal)
            palabra = fgetc(archivo);
            printf("\n\nID: %0.2X:", palabra);
            palabra = fgetc(archivo);
            printf("%0.2X\n", palabra);

            // BANDERAS
            palabra = fgetc(archivo);
            for(int i=7;i>=0;i--)
                binario[i]=((palabra & (1 << i)) ? 1 : 0);

            campoRespuesta = banderas16_1();

            palabra = fgetc(archivo);
            for(int i=7;i>=0;i--)
                binario[i]=((palabra & (1 << i)) ? 1 : 0);

            banderas16_2();

            dec16=0;
            // CONTADORES
            for(int i=1; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);
                if(i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();
            }
            cout << "\nQDcount: " << dec16;
            dec16=0;

            for(int i=1; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                if(i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();
            }
            cout << "\nANcount: " << dec16;
            dec16=0;

            for(int i=1; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                if(i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();
            }
            cout << "\nNScount: " << dec16;
            dec16=0;

            for(int i=1; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                if(i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();
            }
            cout << "\nARcount: " << dec16;
            dec16=0;
        }



        // CAMPO DE PREGUNTA
        cout << "\n\nCAMPOS DE PREGUNTA\n";

        //printf("\nPalabra: %0.2x\n", palabra); // 05
        while(auxflag==0){
            palabra = fgetc(archivo);
            for(int i=7;i>=0;i--)
                binario[i]=((palabra & (1 << i)) ? 1 : 0);

            dec8 = bin_dec();
            if(dec8!=0){
                if(dec8<16){
                for(int i=0; i<dec8; i++){
                    palabra = fgetc(archivo);
                    cout << palabra;
                }
                cout << ".";
                }
            }else{
                auxflag = 1;
            }
        }
        // TIPO
        dec16 = 0;
        auxflag = 0;
        for(int i=3; i>=0; i--){
            palabra = fgetc(archivo);
            for(int i=7;i>=0;i--)
                binario[i]=((palabra & (1 << i)) ? 1 : 0);

            if(i==3 or i==1)
                dec16 = byte1_LTI();
            else
                dec16 = dec16 + byte2_LTI();

            if(i==2){
                dec16 = tipoDNS(dec16);
            }
            else if(i==0){
                claseDNS(dec16);
            }
        }

        // CAMPOS DE RESPUESTA
        if(campoRespuesta==1){
            cout << "\nSI HAY RESPUESTAS" << endl;
            palabra = fgetc(archivo);
            cout << palabra << ".";
            palabra = fgetc(archivo);
            cout << palabra << endl;

            // TIPO RESPUESTA
            dec16 = 0;
            auxflag = 0;
            for(int i=3; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                if(i==3 or i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();

                if(i==2){
                    dec16 = tipoDNS(dec16);
                }
                else if(i==0){
                    claseDNS(dec16);
                }
            }

            // TTL (TIEMPO DE VIDA, SEGUNDOS) 4 BYTES
            dec32 = 0;
            for(int i=0; i<=3; i++){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                //printf("\nPalabra: %0.2x\n", palabra);
                if(i==0)
                    dec32 = byte4_LTI();
                else if(i==1)
                    dec32 = dec32 + byte3_LTI();
                else if(i==2)
                    dec32 = dec32 + byte1_LTI();
                else
                    dec32 = dec32 + byte2_LTI();
            }
            cout << "\nTTL: " << dec32;

            // LONGITUD DE DATOS (2 BYTES)
            dec16 = 0;
            for(int i=1; i>=0; i--){
                palabra = fgetc(archivo);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                if(i==1)
                    dec16 = byte1_LTI();
                else
                    dec16 = dec16 + byte2_LTI();
            }
            cout << "\nLongitud de datos: " << dec16 << endl;

        }
        else{
            cout << "\n\nNO HAY RESPUESTAS" << endl;
        }

        // DATOS
        cout << "\nDATOS\n";
        while(!feof(archivo)){
            palabra = fgetc(archivo);
            printf(":%0.2X", palabra);
            //break;
        }
    }
    return 0;

}
