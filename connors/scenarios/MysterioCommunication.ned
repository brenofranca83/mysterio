package mysterio.connors.scenarios;

import inet.node.inet.StandardHost;
import mysterio.connors.uavs.ModuloComunicacao;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;
import inet.node.base.ApplicationLayerNodeBase;

network MysterioCommunication {
    parameters:
        int numHosts;
        @display("bgb=1000,1000");
    submodules:
        visualizer: IntegratedVisualizer {
            @display("p=100,50");
        }
        canvasVisualizer: IntegratedCanvasVisualizer {
            @display("p=100,50");
        }
        host[numHosts]: ModuloComunicacao {
            @display("i=misc/node_vs");
        }
    connections:
        host[0].out++ --> {  delay = 100ms; } --> host[1].in++;
        host[0].in++ <-- {  delay = 100ms; } <-- host[1].out++;
        host[0].out++ --> {  delay = 100ms; } --> host[2].in++;
        host[0].in++ <-- {  delay = 100ms; } <-- host[2].out++;
        host[0].out++ --> {  delay = 100ms; } --> host[3].in++;
        host[0].in++ <-- {  delay = 100ms; } <-- host[3].out++;
        host[0].out++ --> {  delay = 100ms; } --> host[4].in++;
        host[0].in++ <-- {  delay = 100ms; } <-- host[4].out++;
}
