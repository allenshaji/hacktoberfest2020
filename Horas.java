package horas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.DecimalFormat;
import javax.swing.Timer;

public class Horas extends JFrame{

    JLabel rotulo,rotulo1;
    int hh,mm,ss,h;
    Calendar hora;
    DecimalFormat formato;
    public Horas(){
    super("Exemplo de Hora");
    Container tela = getContentPane();
    tela.setLayout(null);    
    rotulo = new JLabel("");
    rotulo.setBounds(100,60,280,20);
    rotulo1 = new JLabel("Horas no Formato hhmmss");
    rotulo1.setBounds(60,05,280,20);
        ActionListener tarefa = (new ActionListener () {
        public void actionPerformed(ActionEvent e){
        HORAS();
        }    
        });
        javax.swing.Timer time = new javax.swing.Timer(1000,tarefa);
        time.start();
        tela.add(rotulo);
        tela.add(rotulo1);
        setSize(300, 200);
        setVisible(true);
        setLocationRelativeTo(null);
    }
public static void main(String args[]){
    Horas app = new Horas();
    app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
} 

private void HORAS(){
    hora = Calendar.getInstance();
    hh = hora.get(Calendar.HOUR_OF_DAY);
    mm = hora.get(Calendar.MINUTE);
    ss = hora.get(Calendar.SECOND);
    rotulo.setText("Hora: "+formatar(hh%12)+":"+formatar(mm)+":"+formatar(ss));
    //Texto1.setFont(new Font("NomeFonte",Font.ESTILO,TAMANHO));
}
private String formatar(int num) {
    formato = new DecimalFormat("00");
    return formato.format(num);
}
    
    
}
