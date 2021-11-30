function [ ] = microdaqBeforeMakeHook( modelName, buildOpts, buildInfo )

% Check the model if a target_paths.mk should be created
if (strcmp(get_param(modelName,'SystemTargetFile')  ,'microdaq.tlc') && ...
        strcmp(get_param(modelName,'TemplateMakefile')  ,'microdaq.tmf') && ...
        strcmp(get_param(modelName,'TargetHWDeviceType'),'Texas Instruments->C6000'))
    
    TargetRoot = getpref('microdaq','TargetRoot');
    CompilerRoot = getpref('microdaq','CompilerRoot');
    
    
    % check if sysbios.mk exists
    if ~exist([TargetRoot, '/sysbios.mk'],'file')
        error('Error: Run mdaqPing to detect your hardware first');
    end
    
    % Create the target paths makefile
    makefileName = 'target_paths.mk';
    fid = fopen(makefileName,'w');
    fwrite(fid, sprintf('%s\n\n', '# MicroDAQ paths'));
    fwrite(fid, sprintf('CompilerRoot  = %s\n', CompilerRoot));
    fwrite(fid, sprintf('TargetRoot    = %s\n', TargetRoot));
    % Use target paths makefile to pass information about sample time
    Ts = str2double(get_param(modelName,'FixedStep'));
    % User timer is in microseconds
    if isnan(Ts)
        % 'auto' in model
        Ts = 0.2*1e6;
    else
        Ts = Ts*1e6;
    end
    fprintf(fid,'SAMPLE_TIME = %s\n',num2str(Ts));
    if isExternalMode(buildInfo)
        fprintf(fid, 'EXT_MODE = 1');
        try
            buildInfo.removeSourceFiles({'updown.c','ext_work.c','ext_svr.c'});
        catch
        end
    end
    fclose(fid);
    try
        buildInfo.removeSourceFiles('rt_main.c');
    catch
    end
    if buildOpts.codeWasUpToDate
        % Perform hook actions for up to date model
    else
        % Perform hook actions for full code generation
        % Force rebuild of static external mode main (ext_main.c)
        if exist('ext_main.o','file')
            delete('ext_main.o');
        end
    end
end
end

function res = isExternalMode(buildInfo)
[~, res] = buildInfo.findBuildArg('EXT_MODE');
res = str2double(res);
end
